#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

/*
  Ͱ���򡣣�Ҳ������ʱ�����򷨵�һ�֣�

  ÿ��Ͱ��bucket������һ�����䷶Χ��������Գ���һ������Ԫ�ء�

*/


//��ע��1�������д�Сvec.size()�Ƚ�С����Ԫ��ֵ�ܴ��ҷ�ɢ(max - min�Ƚϴ�)������ɺܶࡰ��Ͱ��, ����ϵͳ����. ����(0, 13, 19892)����> �ܶࡰ��Ͱ��
//��ע��2����������������Ԫ�ظ����ܶ�(vec.size()�ܴ�), ����ÿ��Ԫ��ȴ�ֺ�Сʱ, ֻ��һ��Ͱ, ��������ȽϺ�ʱ

//ѡ������
void SelectSort(vector<double>&vec)
{
	int minPos = -1;   //���ѡ������Сֵ��λ��
	int len = vec.size();
	for (size_t i = 0; i < len - 1; i++)  //�����ѭ�����ܹ�Ҫ������-1��
	{
		minPos = i;
		for (size_t j = i + 1; j < len; j++)	// ��������
		{
			if (vec[minPos] > vec[j])
			{
				minPos = j;
			}
		}

		if (minPos != i)     //˵�����±�Ϊ��i��n�������¼���ҵ��˸�С�ļ�¼minPos��Ҫ���±�Ϊi�ļ�¼����λ�á��൱����Сֵǰ��
		{
			double tmp = vec[minPos];
			vec[minPos] = vec[i];
			vec[i] = tmp;
		}
	}
}


double* sortBucket(double arr[], int size)
{
	//1���õ����е����ֵ����Сֵ���������ֵd
	double max = arr[0];
	double min = arr[0];
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
	double d = max - min;


	//2����ʼ��Ͱ
	int bucketNum = d/size+1;
	vector<vector<double>>bucketList(bucketNum); // ��ʼ��Ͱ, ����������ʵ��, Ҳ������vectorʵ��, ����ѡȡvectorʵ��, ԭ������
	// int** buckets = new int*[bucketNum];	// ����ʵ��Ͱ����Ҫ��ά����
	
	for (int i = 0; i < bucketNum; i++)
	{
		vector<double>bucketVec;
		bucketList.push_back(bucketVec);
	}

	//3������ԭʼ���飬��ÿ��Ԫ�ط����ӦͰ��
	for (int i = 0; i < size; i++)
	{

		if (bucketNum == 1)
		{
			bucketList[0].push_back(arr[i]);
		}
		else
		{
			int bucketIndex = (arr[i] - min) / bucketNum; //ȷ��������ĸ�Ͱ
			bucketIndex = bucketIndex >= bucketNum ? bucketNum - 1 : bucketIndex;
			bucketList[bucketIndex].push_back(arr[i]);
		}
	}

	double* sortedArray = new double[size];
	int index = 0;
	//4������Ͱ����ÿ��Ͱ�е�Ԫ���������������������ˣ�
	for (vector<vector<double> >::iterator iter = bucketList.begin(); iter != bucketList.end(); iter++)
	{
		vector<double>vecTmp = *iter;
		if (vecTmp.size() <= 0)
		{
			continue;
		}

		// ��ÿ��Ͱ��������, �������ѡ������
		// ��n��Сʱ�����ȶ��Բ���Ҫ��ʱ����ѡ������
		SelectSort(vecTmp);
		// InsertSort(vecTmp);	// ����Ȥ����Ҳ�������ò������򿴿�

		for (auto t : vecTmp)  //����ÿ��Ͱ�е�Ԫ�أ����δ���������������
		{
			sortedArray[index] = t;
			index++;
		}
	}
	return sortedArray;
}
	
	////�������õĽ��
	//double* sortedArray = new double[size];
	//int index = 0;
	//for (auto it:bucketList)
	//{
	//	for(auto t:it)
	//	{
	//		sortedArray[index] = t;
	//		index++;
	//	}

	//}
//}



int main()
{
	double amm[] = { 4.12,6.421,0.0023,3.0,2.123,8.122,4.12,1.0 };
	int size = sizeof(amm) / sizeof(double);
	double* sortedArray = sortBucket(amm, size);
	for (int i = 0; i < size; i++)
	{
		cout << sortedArray[i] << " ";
	}

	return 0;
}







