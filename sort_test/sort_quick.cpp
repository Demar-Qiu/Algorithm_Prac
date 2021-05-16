#include<iostream>
#include<stdlib.h>
#include<map>
#include<stack>
#include<unordered_map>
using namespace std;


/* 

  对快速排序算法的学习。

  类似冒泡排序，也是比较交换元素。不同的是冒泡排序每一轮中只把一个元素冒泡到数列一端，
  而快速排序则在每一轮选一个基准元素，并让其他比它大的元素移动到数列一边，比它小的元
  素移到另一边，从而拆成两个部分，叫做“分治法”。

  由于数列在每一轮都被拆分为两部分，每一轮时间复杂度为O(n)，平均需要进行logn轮，因此
  总体时间复杂度为O(nlogn)

  关键：基准元素的选择和元素的交换

*/

// 通常选择首元素为基准元素。
// 注意有极端情况：选的基准元素是最小或最大值，这样就无法实现分治，时间复杂度退化为O(n^2)
//                 这样 通常随机选一个元素为基准并与首元素交换（但也不能完全解决）

// 以下省去了随机选择基准元素的过程，把首元素作为基准。



// 1、双边循环法实现：（选定一个基准元素、两个指针left和right，指向数列最左和最右两个元素）
int partition(int arr[], int, int);
void quickSort(int arr[], int startIndex, int endIndex)
{
	// 递归结束条件：startIndex>=endIndex
	if (startIndex >= endIndex)
	{
		return;
	}

	// 得到基准元素位置
	int pivotIndex = partition(arr, startIndex, endIndex);
	// 根据基准元素，分成两部分进行递归排序  每次根据上一次得到的基准元素位置，各自分而治之
	quickSort(arr, startIndex, pivotIndex - 1);  
	quickSort(arr, pivotIndex + 1, endIndex);

}

// 分治（双边循环）函数：
int partition(int arr[], int startIndex, int endIndex)
{
	// 这里取首元素为基准元素（也可以取任意元素）
	int pivot = arr[startIndex];
	int left = startIndex;
	int right = endIndex;

	while (left != right)
	{
		// 控制right指针 与基准元素比较并左移（大于或等于pivot则左移，否则停在那）
		while (left<right && arr[right]>pivot)
		{
			right--;
		}
		// 控制left指针 与基准元素比较并右移（小于或等于pivot则右移，否则停在那）
		while (left < right && arr[left] <= pivot)
		{
			left++;
		}

		//交换left和right指针指向的元素
		if (left < right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
	//一轮最后将pivot与重合点元素交换(left和right重合)
	arr[startIndex] = arr[left];   //这里重合点便到了首元素位置
	arr[left] = pivot;

	return left; //返回此时的pivot位置

}


int partition1(int arr[], int, int);
// 1、单边循环法实现：（选定一个基准元素、一个mark指针指向起始位置，代表小于基准元素的区域边界）
   // 与双边的区别在于partition函数
void quickSort1(int arr[], int startIndex, int endIndex)
{

	// 递归结束条件：startIndex>=endIndex
	if (startIndex >= endIndex)
	{
		return;
	}

	// 得到基准元素位置
	int pivotIndex = partition1(arr, startIndex, endIndex);
	// 根据基准元素，分成两部分进行递归排序  每次根据上一次得到的基准元素位置，各自分而治之
	quickSort1(arr, startIndex, pivotIndex - 1);
	quickSort1(arr, pivotIndex + 1, endIndex);
}

// 分治（单边循环）函数：
int partition1(int arr[], int startIndex, int endIndex)
{
	// 这里取首元素为基准元素（也可以取任意元素）
	int pivot = arr[startIndex];
	int mark = startIndex;

	//从基准元素的下一位置开始遍历数组，遍历到大于pivot的则继续往后；
	//若遍历到小于pivot的，先把mark指针右移一位（表示小于pivot的区域边界加1）；
	//再让最新遍历到的元素和mark指针所在位置元素交换（归于小于pivot区域
	for (int i = startIndex + 1; i <= endIndex; i++)
	{
		if (arr[i] < pivot)
		{
			mark++;
			int tmp = arr[mark];
			arr[mark] = arr[i];
			arr[i] = tmp;
		}
	}
	//一轮最后将pivot与mark指针所在位置元素交换
	arr[startIndex] = arr[mark];
	arr[mark] = pivot;

	return mark; //返回此时的pivot位置

}






// 以上快排是基于递归实现的，也可以基于非递归实现
// 递归实现一般可转化为栈的实现，在栈中存储每一次方法调用的参数（每调一次函数方法就是入栈；方法返回时就是出栈）
void quickSort2(int arr[], int startIndex, int endIndex)
{
	if (startIndex >= endIndex)
	{
		return;
	}

	// 用一个集合栈来代替递归的函数栈
	stack<int>stackIndex;
	//整个数列的起止下标入栈
	stackIndex.push(startIndex);
	stackIndex.push(endIndex);
	int begin = 0;
	int end = 0;

	//循环条件结束：栈为空时
	while (!stackIndex.empty())
	{
		//栈顶元素出栈，得到起止下标
		end = stackIndex.top();
		stackIndex.pop();
  		begin = stackIndex.top();
		stackIndex.pop();
		//得到基准元素位置
		int pivotIndex = partition1(arr, begin, end);

		//根据基准元素分成两部分，每一部分的起止下标入栈
		if (begin < pivotIndex - 1)
		{
			stackIndex.push(begin);
			stackIndex.push(pivotIndex - 1);
		}
		if (end > pivotIndex + 1)
		{
			stackIndex.push(pivotIndex + 1);
			stackIndex.push(end);
		}

	}

}




int main()
{
	int arr[] = { 4,4,6,5,3,2,8,1 };
	int size = sizeof(arr) / sizeof(int);
	quickSort2(arr, 0, size - 1);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}



















