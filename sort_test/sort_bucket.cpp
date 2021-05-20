#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

/*
  桶排序。（也是线性时间排序法的一种）

  每个桶（bucket）代表一个区间范围，里面可以承载一个或多个元素。

*/


//【注意1】当序列大小vec.size()比较小，而元素值很大且分散(max - min比较大)，会造成很多“空桶”, 增加系统开销. 比如(0, 13, 19892)——> 很多“空桶”
//【注意2】：当待排序序列元素个数很多(vec.size()很大), 但是每个元素却又很小时, 只有一个桶, 这种情况比较耗时

//选择排序法
void SelectSort(vector<double>&vec)
{
	int minPos = -1;   //标记选出的最小值的位置
	int len = vec.size();
	for (size_t i = 0; i < len - 1; i++)  //最外层循环，总共要排总数-1次
	{
		minPos = i;
		for (size_t j = i + 1; j < len; j++)	// 待排序区
		{
			if (vec[minPos] > vec[j])
			{
				minPos = j;
			}
		}

		if (minPos != i)     //说明在下标为从i至n的无序记录中找到了更小的记录minPos，要与下标为i的记录交换位置。相当于最小值前移
		{
			double tmp = vec[minPos];
			vec[minPos] = vec[i];
			vec[i] = tmp;
		}
	}
}


double* sortBucket(double arr[], int size)
{
	//1、得到数列的最大值和最小值，并算出差值d
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


	//2、初始化桶
	int bucketNum = d/size+1;
	vector<vector<double>>bucketList(bucketNum); // 初始化桶, 可以用数组实现, 也可以用vector实现, 这里选取vector实现, 原因下述
	// int** buckets = new int*[bucketNum];	// 数组实现桶，需要二维数组
	
	for (int i = 0; i < bucketNum; i++)
	{
		vector<double>bucketVec;
		bucketList.push_back(bucketVec);
	}

	//3、遍历原始数组，将每个元素放入对应桶中
	for (int i = 0; i < size; i++)
	{

		if (bucketNum == 1)
		{
			bucketList[0].push_back(arr[i]);
		}
		else
		{
			int bucketIndex = (arr[i] - min) / bucketNum; //确定存放在哪个桶
			bucketIndex = bucketIndex >= bucketNum ? bucketNum - 1 : bucketIndex;
			bucketList[bucketIndex].push_back(arr[i]);
		}
	}

	double* sortedArray = new double[size];
	int index = 0;
	//4、遍历桶，对每个桶中的元素排序（这样整个就有序了）
	for (vector<vector<double> >::iterator iter = bucketList.begin(); iter != bucketList.end(); iter++)
	{
		vector<double>vecTmp = *iter;
		if (vecTmp.size() <= 0)
		{
			continue;
		}

		// 对每个桶进行排序, 这里借用选择排序
		// 当n较小时，对稳定性不作要求时宜用选择排序
		SelectSort(vecTmp);
		// InsertSort(vecTmp);	// 有兴趣读者也可以试用插入排序看看

		for (auto t : vecTmp)  //遍历每个桶中的元素，依次存入排序后的数组中
		{
			sortedArray[index] = t;
			index++;
		}
	}
	return sortedArray;
}
	
	////输出排序好的结果
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







