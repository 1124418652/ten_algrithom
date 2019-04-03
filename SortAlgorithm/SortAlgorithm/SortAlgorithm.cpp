// SortAlgorithm.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

// �鲢����
void mergeSort(vector<int> &q, int left, int right);

// ������
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
�鲢����:
1. �����зֳ��������벿����������
2. �������������������н��кϲ�
*/
void mergeSort(vector<int> &q, int left, int right)
{
	if (left == right)
		return;
	int mid = (left + right) / 2;     // mid ����ȡ��
	mergeSort(q, left, mid);          // ����벿�ֽ��й鲢����
	mergeSort(q, mid + 1, right);     // ���Ұ벿�ֽ��й鲢����

	
	// ����벿�ֺ��Ұ벿�ֶ�����������ʱ�����ж�·�ϲ�
	int LEFT_SIZE = mid - left + 1;
	int RIGHT_SIZE = right - mid;
	int i = 0, j = 0, k = 0;   // ѭ������
	vector<int> leftArr;
	vector<int> rightArr;
	for (i = left; i < mid + 1; ++i)           // 1.����������������
		leftArr.push_back(q[i]);
	for (i = mid + 1; i <= right; ++i)
		rightArr.push_back(q[i]);              // 2.����������������

	i = 0; j = 0; k = left;                    // 3.����������������ԭ�����У�ע��kҪ��left��ʼ
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
������:
1.�Ƚ�һ����������һ���ѣ������һ������ѵĻ����ѵ�����һ���ڵ��ֵһ��������
2.���ѵĵ�һ���ڵ㣨���ֵ����ѵ����һ���ڵ���������Ȼ�󿳶����һ���ڵ�ı�
3.������һ������֮�󣬶��ڵ��������ӽڵ�Ķѽṹ�Ѿ����ƻ��ˣ�������Ҫ�������heapify,
  �����Զ��ڵ�������ӽڵ�Ϊ���ڵ���������Ǳ��ֶѽṹ�ģ�������ʹ��heapify�����ˣ�������
  buildHeap
4.�ظ�����3��ֱ��ֻ��һ���ڵ�ʱ�˳�ѭ��
*/

// �ݹ麯������parent���µ����нڵ㹹��һ����
void heapify(vector<int> &q, int parent, int num) 
{
	int n = num;    // ��ȡ�����һ��Ԫ�ص�����
	if (parent >= n)              // ���parent������ֵ�Ѿ����ڵ������һ���ڵ㣬˵���Ѿ�û���ӽڵ�
		return;
	int lChild = parent * 2 + 1;
	int rChild = parent * 2 + 2;
	int max = parent;
	
	// �Ҹ��ڵ�������ӽڵ��е����ֵ
	if (lChild <= n && q[lChild] > q[max])    // �ڱ�֤�ӽڵ��ֵ��������ǰ�����������ڵ��е����ֵ
		max = lChild;
	if (rChild <= n && q[rChild] > q[max])
		max = rChild;

	// �����ֵ���ڵĽڵ��븸�ڵ���н���
	if (max != parent) {
		swap(q[max], q[parent]);
		// ��Ϊ�ڸ������ڣ�maxָ��Ľڵ��ֵ�������˽�����������maxΪ���ڵ�����Ķѽṹ���ܱ�
		// �ƻ��ˣ������Ҫ����maxΪ���ڵ�����������ɶѡ���û���������Ľڵ㣬���Ķѽṹû�б�
		// �ƻ������Բ����������ɶ�
		heapify(q, max, n);
	}
}

// ��һ����ȫ�����������ɶ�
void buildHeap(vector<int> &q)
{
	int lastNode = (int)q.size() - 1;   // ��ȡ���һ���ڵ������
	int lParent = (lastNode - 1) / 2;   // ��ȡ���һ���ڵ�ĸ��ڵ���������Ӹýڵ㿪ʼ����heapify����
	for (int i = lParent; i >= 0; --i)
	{
		heapify(q, i, lastNode);
	}
}

// ���ж�����
void heapSort(vector<int> &q)
{
	buildHeap(q);
	int lastNode = (int)q.size() - 1;    // ��ȡ���һ���ڵ������
	for (int i = lastNode; i >= 0; --i)
	{
		swap(q[0], q[i]);     // �����Ѷ������һ���ڵ��ֵ
		heapify(q, 0, i-1);     // �������һ���ڵ�ıߵĲ���������heapify(q,i-1)�����棬��Ϊi�ǵݼ���
	}
}