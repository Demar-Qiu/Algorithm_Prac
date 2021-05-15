#include<iostream>
#include<stdlib.h>
using namespace std;


/* 
  根据漫画算法---小灰的算法之旅

  对冒泡排序算法的学习和优化

*/


// 原始冒泡排序法
void BubbleSort(int array[],int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			int temp = 0;
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

}

// 优化1：（针对已经提前出现有序的情况，做出标记，可以省去之后几轮排序）

void BubbleSort1(int array[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		// 进行有序标记，初始值设为true
		bool isSorted = true;
		for (int j = 0; j < size - i - 1; j++)
		{
			int temp = 0;
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				//有元素交换的情况下，说明不是有序，标记变为false
				isSorted = false;
			}
		}
		if (isSorted)
		{
			break;
		}
	}

}



//优化2：（针对数列的有序区进行界定，可能提前出现很长一段有序区，这样之后就不用再比较）
void BubbleSort2(int array[], int size)
{
	//记录最后一次交换的位置
	int lastExchangeIndex = 0;

	//无序数列的边界，每次比较只需比到这里为止
	int sortBorder = size - 1;  //初始位置是最后（因为前面大的都是往后移的）
	for (int i = 0; i < size - 1; i++)
	{

		// 进行有序标记，初始值设为true
		bool isSorted = true;
		for (int j = 0; j < sortBorder; j++)
		{
			int temp = 0;
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				//有元素交换的情况下，说明不是有序，标记变为false
				isSorted = false;

				//更新为最后一次交换元素的位置
				lastExchangeIndex = j;
			}
		}
		sortBorder = lastExchangeIndex;
		if (isSorted)
		{
			break;
		}
	}

}






int main()
{
	int array1[] = { 2,5,8,3,1,6,7,9,4 };
	int array2[] = { 5,8,6,3,9,2,1,7 };
	int array3[] = { 3,4,2,1,5,6,7,8 };

	int len1 = sizeof(array1) / sizeof(int);
	int len2 = sizeof(array2) / sizeof(int);
	int len3 = sizeof(array3) / sizeof(int);

	for (int k = 0; k < len1; k++)
	{
		cout << array1[k] << " ";
	}
	cout << endl;
	BubbleSort(array1, len1);
	cout << "The sorted array are:"<<endl;
	for (int k = 0; k < len1; k++)
	{
		cout << array1[k] << " ";
	}
	cout << endl;

	cout << "------------------------" << endl;

	for (int k = 0; k < len2; k++)
	{
		cout << array2[k] << " ";
	}
	cout << endl;
	BubbleSort1(array2, len2);
	cout << "The sorted array are:" << endl;
	for (int k = 0; k < len2; k++)
	{
		cout << array2[k] << " ";
	}
	cout << endl;

	cout << "------------------------" << endl;

	for (int k = 0; k < len3; k++)
	{
		cout << array3[k] << " ";
	}
	cout << endl;
	BubbleSort2(array3, len3);
	cout << "The sorted array are:" << endl;
	for (int k = 0; k < len3; k++)
	{
		cout << array3[k] << " ";
	}
	cout << endl;


	return 0;
}