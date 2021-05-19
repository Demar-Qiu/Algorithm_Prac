#include<iostream>
#include<stdlib.h>
using namespace std;

/* 
* 
  ������ ��ʱ�临�Ӷ�ΪO(nlogn)��
  ���������鹹���ɶ���ѡ���Ҫ��С���������򹹽������ѣ����Ӵ�С�����򹹽�����С�ѡ�
  ѭ��ɾ���Ѷ�Ԫ�أ��滻������ѵ�ĩβ�������Ѳ����µĶѶ���

*/

/* �³����� */
void downAdjust(int arr[], int parentIndex, int length)   //arr�������Ķ�,parentIndexҪ�³��ĸ��ڵ� ��length�ѵ���Ч��С
{
    // temp���游�ڵ��ֵ���������ĸ�ֵ����
    int temp = arr[parentIndex];
    int childIndex = 2 * parentIndex + 1;  //��λ����
    while (childIndex < length)
    {
        //������Һ��ӣ����Һ��Ӵ������ӣ���λ���Һ��ӣ����ڵ�С�����Һ��ӽڵ㣬�����Ľ�����
        if (childIndex + 1 < length && arr[childIndex + 1] > arr[childIndex])
        {
            childIndex++;  // ��λ���Һ���
        }
        // ������ڵ�����κ�һ�����ӵ�ֵ����ֱ������(˵���³����)
        if (temp >= arr[childIndex])     //����Ҫ�õ�����  
            break;                       //��Ϊ���︸�ڵ����Ҫ���������ӱȴ�С�����Բ��÷����ܵ�whileѭ��������

        // ���������������ӽڵ㵥��ֵ����,���Ǹ��ڵ��³�ǰ��λ��
        arr[parentIndex] = arr[childIndex];
        parentIndex = childIndex;
        childIndex = 2 * childIndex + 1;

    }
    arr[parentIndex] = temp;   //�³���ɺ󽫸ý��ֵ��ֵ����Ӧλ��

}


// ����
void sortHeap(int arr[],int size)
{
    // 1�����������鹹��������
    for (int i = (size - 2) / 2; i >= 0; i--)
    {
        downAdjust(arr, i, size);
    }
    // 2��ѭ��ɾ���Ѷ�Ԫ�أ��Ƶ�����β��(���ڶ����˹�)�������Ѳ����µĶѶ�
    for (int i = size - 1; i > 0; i--)
    {
        //���һ��Ԫ�غ͵�һ��Ԫ�ؽ��н���
        int tmp = arr[i];
        arr[i] = arr[0];
        arr[0] = tmp;
        //�³���������
        downAdjust(arr, 0, i);
    }
}


int main_3()
{
    int arc[] = { 1,3,2,6,5,7,8,9,10,0 };
    int length = sizeof(arc) / sizeof(int);
    sortHeap(arc, length);
    for (int k = 0; k < length; k++)
    {
        cout << arc[k] << " ";  //�������
    }
    return 0;
}









