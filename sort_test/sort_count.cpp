#include<iostream>
#include<stdlib.h>
using namespace std;

/* 
  ���������㷨��  
  
  ʱ�临�Ӷ� O(n+m�� nΪԭʼ���й�ģ��mΪͳ�������ģ

  ��һ���������а���Ԫ��ֵ����һ���µ�ͳ�����飬ͳ��������±��������Ԫ��ֵ��ÿ���±��Ӧ��ֵΪ��Ԫ�س��ֵĴ���
  ���������������˳�����������м�����������Σ����ܵõ������
  �Ż�������ͳ�����飬�ӵڶ���Ԫ�ؿ�ʼÿ��Ԫ�ض�Ҫ����ǰ��Ԫ��֮��
        ��������ͳ������洢��Ԫ��ֵ������ӦҪ�����λ����š�

  �����ԣ�1�����ʺ��ڷ��������޷�������Ӧ��ͳ�����飩��2�����ʺ��ڶԿ�Ⱥܴ���������򣨼����ֵ����Сֵ������
*/

int* sortCount(int arr[],int size)
{
	//1���õ����е����ֵ����Сֵ�����ó���ֵd
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

	//2������ͳ�����鲢ͳ�ƶ�ӦԪ�صĸ���
	int* countArr = new int[d + 1];
	for (int i = 0; i < d+1; i++)
	{
		countArr[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		countArr[arr[i] - min]++;  //��ʾ��Ԫ��ֵ�ĸ���
	}

	//3��ͳ�����������Σ������Ԫ�ص���ǰ���Ԫ��֮��
	for (int i = 1; i < d+1; i++)
	{
		countArr[i] += countArr[i - 1];   
	}

	//4���������ԭʼ���У���ͳ�������ҵ���ȷλ�ã�����������
	int* sortedArr = new int[size];
	for (int i = 0; i < size; i++)
	{
		sortedArr[i] = 0;
	}
	for (int i = size - 1; i >= 0; i--)
	{
		sortedArr[countArr[arr[i] - min] - 1] = arr[i]; //��Ԫ��ֵ��ֵ��������������Ӧλ��
		countArr[arr[i] - min]--;   //������һ�������´����������������Ԫ��ֵʱ����ǰ��һλ
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






