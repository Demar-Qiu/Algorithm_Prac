#include<iostream>
#include<stdlib.h>
using namespace std;

/* 
  计数排序算法。  
  
  时间复杂度 O(n+m） n为原始数列规模，m为统计数组规模

  把一组无序数列按照元素值构成一组新的统计数组，统计数组的下标包括所有元素值，每个下标对应的值为该元素出现的次数
  最后按照这个新数组的顺序遍历输出（有几个次输出几次）就能得到结果。
  优化：变形统计数组，从第二个元素开始每个元素都要加上前面元素之和
        这样可让统计数组存储的元素值等于相应要排序的位置序号。

  局限性：1、不适合于非整数（无法创建对应的统计数组）；2、不适合于对跨度很大的数列排序（即最大值和最小值差距过大）
*/

int* sortCount(int arr[],int size)
{
	//1、得到数列的最大值和最小值，并得出差值d
	int max = arr[0];
	int min = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	int d = max - min;

	//2、创建统计数组并统计对应元素的个数
	int* countArr = new int[d + 1];
	for (int i = 0; i < d+1; i++)
	{
		countArr[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		countArr[arr[i] - min]++;  //表示该元素值的个数
	}

	//3、统计数组做变形，后面的元素等于前面的元素之和
	for (int i = 1; i < d+1; i++)
	{
		countArr[i] += countArr[i - 1];   
	}

	//4、倒序遍历原始数列，从统计数组找到正确位置，输出结果数组
	int* sortedArr = new int[size];
	for (int i = 0; i < size; i++)
	{
		sortedArr[i] = 0;
	}
	for (int i = size - 1; i >= 0; i--)
	{
		sortedArr[countArr[arr[i] - min] - 1] = arr[i]; //该元素值赋值给排序后数组的相应位置
		countArr[arr[i] - min]--;   //计数减一，代表下次再遇到这个计数的元素值时排名前移一位
	}
	return sortedArr;

}

int main()
{
	int arrm[] = { 95,94,91,98,99,90,99,93,91,92 };
	int size = sizeof(arrm) / sizeof(int);
	int* sortedArray = sortCount(arrm,size);
	for (int k = 0; k < size; k++)
	{
		cout << sortedArray[k] << " ";
	}

	return 0;
}






