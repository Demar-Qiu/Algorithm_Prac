#include<iostream>
#include<stdlib.h>
#include<map>
#include<stack>
#include<unordered_map>
using namespace std;


/* 

  �Կ��������㷨��ѧϰ��

  ����ð������Ҳ�ǱȽϽ���Ԫ�ء���ͬ����ð������ÿһ����ֻ��һ��Ԫ��ð�ݵ�����һ�ˣ�
  ��������������ÿһ��ѡһ����׼Ԫ�أ����������������Ԫ���ƶ�������һ�ߣ�����С��Ԫ
  ���Ƶ���һ�ߣ��Ӷ�����������֣����������η�����

  ����������ÿһ�ֶ������Ϊ�����֣�ÿһ��ʱ�临�Ӷ�ΪO(n)��ƽ����Ҫ����logn�֣����
  ����ʱ�临�Ӷ�ΪO(nlogn)

  �ؼ�����׼Ԫ�ص�ѡ���Ԫ�صĽ���

*/

// ͨ��ѡ����Ԫ��Ϊ��׼Ԫ�ء�
// ע���м��������ѡ�Ļ�׼Ԫ������С�����ֵ���������޷�ʵ�ַ��Σ�ʱ�临�Ӷ��˻�ΪO(n^2)
//                 ���� ͨ�����ѡһ��Ԫ��Ϊ��׼������Ԫ�ؽ�������Ҳ������ȫ�����

// ����ʡȥ�����ѡ���׼Ԫ�صĹ��̣�����Ԫ����Ϊ��׼��



// 1��˫��ѭ����ʵ�֣���ѡ��һ����׼Ԫ�ء�����ָ��left��right��ָ�������������������Ԫ�أ�
int partition(int arr[], int, int);
void quickSort(int arr[], int startIndex, int endIndex)
{
	// �ݹ����������startIndex>=endIndex
	if (startIndex >= endIndex)
	{
		return;
	}

	// �õ���׼Ԫ��λ��
	int pivotIndex = partition(arr, startIndex, endIndex);
	// ���ݻ�׼Ԫ�أ��ֳ������ֽ��еݹ�����  ÿ�θ�����һ�εõ��Ļ�׼Ԫ��λ�ã����Էֶ���֮
	quickSort(arr, startIndex, pivotIndex - 1);  
	quickSort(arr, pivotIndex + 1, endIndex);

}

// ���Σ�˫��ѭ����������
int partition(int arr[], int startIndex, int endIndex)
{
	// ����ȡ��Ԫ��Ϊ��׼Ԫ�أ�Ҳ����ȡ����Ԫ�أ�
	int pivot = arr[startIndex];
	int left = startIndex;
	int right = endIndex;

	while (left != right)
	{
		// ����rightָ�� ���׼Ԫ�رȽϲ����ƣ����ڻ����pivot�����ƣ�����ͣ���ǣ�
		while (left<right && arr[right]>pivot)
		{
			right--;
		}
		// ����leftָ�� ���׼Ԫ�رȽϲ����ƣ�С�ڻ����pivot�����ƣ�����ͣ���ǣ�
		while (left < right && arr[left] <= pivot)
		{
			left++;
		}

		//����left��rightָ��ָ���Ԫ��
		if (left < right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
	//һ�����pivot���غϵ�Ԫ�ؽ���(left��right�غ�)
	arr[startIndex] = arr[left];   //�����غϵ�㵽����Ԫ��λ��
	arr[left] = pivot;

	return left; //���ش�ʱ��pivotλ��

}


int partition1(int arr[], int, int);
// 1������ѭ����ʵ�֣���ѡ��һ����׼Ԫ�ء�һ��markָ��ָ����ʼλ�ã�����С�ڻ�׼Ԫ�ص�����߽磩
   // ��˫�ߵ���������partition����
void quickSort1(int arr[], int startIndex, int endIndex)
{

	// �ݹ����������startIndex>=endIndex
	if (startIndex >= endIndex)
	{
		return;
	}

	// �õ���׼Ԫ��λ��
	int pivotIndex = partition1(arr, startIndex, endIndex);
	// ���ݻ�׼Ԫ�أ��ֳ������ֽ��еݹ�����  ÿ�θ�����һ�εõ��Ļ�׼Ԫ��λ�ã����Էֶ���֮
	quickSort1(arr, startIndex, pivotIndex - 1);
	quickSort1(arr, pivotIndex + 1, endIndex);
}

// ���Σ�����ѭ����������
int partition1(int arr[], int startIndex, int endIndex)
{
	// ����ȡ��Ԫ��Ϊ��׼Ԫ�أ�Ҳ����ȡ����Ԫ�أ�
	int pivot = arr[startIndex];
	int mark = startIndex;

	//�ӻ�׼Ԫ�ص���һλ�ÿ�ʼ�������飬����������pivot�����������
	//��������С��pivot�ģ��Ȱ�markָ������һλ����ʾС��pivot������߽��1����
	//�������±�������Ԫ�غ�markָ������λ��Ԫ�ؽ���������С��pivot����
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
	//һ�����pivot��markָ������λ��Ԫ�ؽ���
	arr[startIndex] = arr[mark];
	arr[mark] = pivot;

	return mark; //���ش�ʱ��pivotλ��

}






// ���Ͽ����ǻ��ڵݹ�ʵ�ֵģ�Ҳ���Ի��ڷǵݹ�ʵ��
// �ݹ�ʵ��һ���ת��Ϊջ��ʵ�֣���ջ�д洢ÿһ�η������õĲ�����ÿ��һ�κ�������������ջ����������ʱ���ǳ�ջ��
void quickSort2(int arr[], int startIndex, int endIndex)
{
	if (startIndex >= endIndex)
	{
		return;
	}

	// ��һ������ջ������ݹ�ĺ���ջ
	stack<int>stackIndex;
	//�������е���ֹ�±���ջ
	stackIndex.push(startIndex);
	stackIndex.push(endIndex);
	int begin = 0;
	int end = 0;

	//ѭ������������ջΪ��ʱ
	while (!stackIndex.empty())
	{
		//ջ��Ԫ�س�ջ���õ���ֹ�±�
		end = stackIndex.top();
		stackIndex.pop();
  		begin = stackIndex.top();
		stackIndex.pop();
		//�õ���׼Ԫ��λ��
		int pivotIndex = partition1(arr, begin, end);

		//���ݻ�׼Ԫ�طֳ������֣�ÿһ���ֵ���ֹ�±���ջ
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



















