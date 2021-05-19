#include<iostream>
#include<stdlib.h>
using namespace std;

/* 
* 
  堆排序。 （时间复杂度为O(nlogn)）
  把无序数组构建成二叉堆。若要从小到大排序，则构建成最大堆；若从大到小排序，则构建成最小堆。
  循环删除堆顶元素，替换到二叉堆的末尾，调整堆产生新的堆顶。

*/

/* 下沉调整 */
void downAdjust(int arr[], int parentIndex, int length)   //arr待调整的堆,parentIndex要下沉的父节点 ，length堆的有效大小
{
    // temp保存父节点的值，用于最后的赋值操作
    int temp = arr[parentIndex];
    int childIndex = 2 * parentIndex + 1;  //定位左孩子
    while (childIndex < length)
    {
        //如果有右孩子，且右孩子大于左孩子，则定位到右孩子（父节点小于左右孩子节点，与更大的交换）
        if (childIndex + 1 < length && arr[childIndex + 1] > arr[childIndex])
        {
            childIndex++;  // 定位到右孩子
        }
        // 如果父节点大于任何一个孩子的值，则直接跳出(说明下沉完毕)
        if (temp >= arr[childIndex])     //这里要得到最大堆  
            break;                       //因为这里父节点可能要和两个孩子比大小，所以不好放在总的while循环条件里

        // 无需真正交换，子节点单向赋值即可,覆盖父节点下沉前的位置
        arr[parentIndex] = arr[childIndex];
        parentIndex = childIndex;
        childIndex = 2 * childIndex + 1;

    }
    arr[parentIndex] = temp;   //下沉完成后将该结点值赋值到相应位置

}


// 升序
void sortHeap(int arr[],int size)
{
    // 1、把无序数组构建成最大堆
    for (int i = (size - 2) / 2; i >= 0; i--)
    {
        downAdjust(arr, i, size);
    }
    // 2、循环删除堆顶元素，移到集合尾部(不在堆中了哈)，调整堆产生新的堆顶
    for (int i = size - 1; i > 0; i--)
    {
        //最后一个元素和第一个元素进行交换
        int tmp = arr[i];
        arr[i] = arr[0];
        arr[0] = tmp;
        //下沉调整最大堆
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
        cout << arc[k] << " ";  //输出升序
    }
    return 0;
}









