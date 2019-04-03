// SortAlgorithm.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

// 归并排序
void mergeSort(vector<int> &q, int left, int right);

// 堆排序
void heapSort(vector<int> &q);
void heapify(vector<int> &q, int parent, int num);
void buildHeap(vector<int> &q);

int main()
{
	vector<int> q = { 23, 5, 56, 2, 54, 65, 32, 23, 543, 2, 3 };
	int left = 0, right = (int)q.size() - 1;
	//mergeSort(q, left, right);
	
	//buildHeap(q);
	heapSort(q);
	for (int x:q)
		cout << x << ' ';
	cout << endl;
    return 0;
}

/*
归并排序:
1. 将序列分成左右两半部分有序序列
2. 将左右两部分有序序列进行合并
*/
void mergeSort(vector<int> &q, int left, int right)
{
	if (left == right)
		return;
	int mid = (left + right) / 2;     // mid 向下取整
	mergeSort(q, left, mid);          // 对左半部分进行归并排序
	mergeSort(q, mid + 1, right);     // 对右半部分进行归并排序

	
	// 当左半部分和右半部分都是有序序列时，进行二路合并
	int LEFT_SIZE = mid - left + 1;
	int RIGHT_SIZE = right - mid;
	int i = 0, j = 0, k = 0;   // 循环变量
	vector<int> leftArr;
	vector<int> rightArr;
	for (i = left; i < mid + 1; ++i)           // 1.对左子数组进行填充
		leftArr.push_back(q[i]);
	for (i = mid + 1; i <= right; ++i)
		rightArr.push_back(q[i]);              // 2.对右子数组进行填充

	i = 0; j = 0; k = left;                    // 3.将两个子数组填充进原数组中，注意k要从left开始
	while (i < LEFT_SIZE && j < RIGHT_SIZE)
	{
		if (leftArr[i] <= rightArr[j]) {
			q[k] = leftArr[i];
			i++;
			k++;
		}
		else {
			q[k] = rightArr[j];
			j++;
			k++;
		}
	}
	while (i < LEFT_SIZE) {
		q[k] = leftArr[i];
		i++;
		k++;
	}
	while (j < RIGHT_SIZE) {
		q[k] = rightArr[j];
		j++;
		k++;
	}
}


/*
堆排序:
1.先将一组数构建成一个堆，如果是一个大根堆的话，堆的最上一个节点的值一定是最大的
2.将堆的第一个节点（最大值）与堆的最后一个节点做交换，然后砍断最后一个节点的边
3.经过上一步交换之后，顶节点与两个子节点的堆结构已经被破坏了，所以需要对其继续heapify,
  但是以顶节点的两个子节点为父节点的树依旧是保持堆结构的，所以是使用heapify就行了，而不是
  buildHeap
4.重复步骤3，直到只有一个节点时退出循环
*/

// 递归函数，将parent往下的所有节点构成一个堆
void heapify(vector<int> &q, int parent, int num) 
{
	int n = num;    // 获取堆最后一个元素的索引
	if (parent >= n)              // 如果parent的索引值已经大于等于最后一个节点，说明已经没有子节点
		return;
	int lChild = parent * 2 + 1;
	int rChild = parent * 2 + 2;
	int max = parent;
	
	// 找父节点和两个子节点中的最大值
	if (lChild <= n && q[lChild] > q[max])    // 在保证子节点的值不会出界的前提下找三个节点中的最大值
		max = lChild;
	if (rChild <= n && q[rChild] > q[max])
		max = rChild;

	// 将最大值所在的节点与父节点进行交换
	if (max != parent) {
		swap(q[max], q[parent]);
		// 因为在该条件内，max指向的节点的值被进行了交换，所以以max为父节点的树的堆结构可能被
		// 破坏了，因此需要对以max为父节点的树重新生成堆。而没经过交换的节点，它的堆结构没有被
		// 破坏，所以不用重新生成堆
		heapify(q, max, n);
	}
}

// 将一颗完全二叉树构建成堆
void buildHeap(vector<int> &q)
{
	int lastNode = (int)q.size() - 1;   // 获取最后一个节点的索引
	int lParent = (lastNode - 1) / 2;   // 获取最后一个节点的父节点的索引，从该节点开始进行heapify操作
	for (int i = lParent; i >= 0; --i)
	{
		heapify(q, i, lastNode);
	}
}

// 进行堆排序
void heapSort(vector<int> &q)
{
	buildHeap(q);
	int lastNode = (int)q.size() - 1;    // 获取最后一个节点的索引
	for (int i = lastNode; i >= 0; --i)
	{
		swap(q[0], q[i]);     // 交换堆顶和最后一个节点的值
		heapify(q, 0, i-1);     // 砍断最后一个节点的边的操作可以由heapify(q,i-1)来代替，因为i是递减的
	}
}