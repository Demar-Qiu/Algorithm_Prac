#include<iostream>
#include<stdlib.h>
using namespace std;


/* 
  ���������㷨---С�ҵ��㷨֮��

  ��ð�������㷨��ѧϰ���Ż�

*/


// ԭʼð������
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

// �Ż�1��������Ѿ���ǰ��������������������ǣ�����ʡȥ֮��������

void BubbleSort1(int array[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		// ���������ǣ���ʼֵ��Ϊtrue
		bool isSorted = true;
		for (int j = 0; j < size - i - 1; j++)
		{
			int temp = 0;
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				//��Ԫ�ؽ���������£�˵���������򣬱�Ǳ�Ϊfalse
				isSorted = false;
			}
		}
		if (isSorted)
		{
			break;
		}
	}

}



//�Ż�2����������е����������н綨��������ǰ���ֺܳ�һ��������������֮��Ͳ����ٱȽϣ�
void BubbleSort2(int array[], int size)
{
	//��¼���һ�ν�����λ��
	int lastExchangeIndex = 0;

	//�������еı߽磬ÿ�αȽ�ֻ��ȵ�����Ϊֹ
	int sortBorder = size - 1;  //��ʼλ���������Ϊǰ���Ķ��������Ƶģ�
	for (int i = 0; i < size - 1; i++)
	{

		// ���������ǣ���ʼֵ��Ϊtrue
		bool isSorted = true;
		for (int j = 0; j < sortBorder; j++)
		{
			int temp = 0;
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				//��Ԫ�ؽ���������£�˵���������򣬱�Ǳ�Ϊfalse
				isSorted = false;

				//����Ϊ���һ�ν���Ԫ�ص�λ��
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


// ���� ����β�������㷨����Զ���Ԫ���Ѿ�����������ֻ�и�������
void CocktailSort(int array[], int size)
{
	int temp = 0;

	for (int i = 0; i < size/2; i++)
	{

		// ���������ǣ���ʼֵ��Ϊtrue  
		bool isSorted = true;
		// �����֣��������ұȽϲ�����
		for (int j = i; j < size-i-1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				//��Ԫ�ؽ���������£�˵���������򣬱�Ǳ�Ϊfalse
				isSorted = false;
			}
		}
		if (isSorted)
		{
			break;
		}

		// ��ż����֮ǰ����isSorted���±��Ϊtrue
		isSorted = true;
		// ż���֣���������Ƚϲ�����
		for (int j = size - i - 1; j > i; j--)
		{
			if (array[j] < array[j - 1])
			{
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
				// ��Ϊ��Ԫ�ؽ��н��������Բ�������
				isSorted = false;
			}
		}
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
	int array4[] = { 2,3,4,5,6,7,8,1 };

	int len1 = sizeof(array1) / sizeof(int);
	int len2 = sizeof(array2) / sizeof(int);
	int len3 = sizeof(array3) / sizeof(int);
	int len4 = sizeof(array4) / sizeof(int);

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

	cout << "------------------------" << endl;

	for (int k = 0; k < len4; k++)
	{
		cout << array4[k] << " ";
	}
	cout << endl;
	CocktailSort(array4, len4);
	cout << "The sorted array are:" << endl;
	for (int k = 0; k < len4; k++)
	{
		cout << array4[k] << " ";
	}
	cout << endl;

	return 0;
}