#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <stack>

#ifndef _GRAPHSEARCH
#define _GRAPHSEARCH



/*
 ͼ�Ĺ�����ȱ���
 @params g �洢ͼ���ڽӱ�
 @params n ͼ�нڵ����Ŀ
*/
void breadthFirstSearch(const std::vector<int> *g, int n);

/*
 ͼ��������ȱ���
 @params g �洢ͼ���ڽӱ�
 @params nodeSearched ��¼ͼ�еĽڵ��Ƿ��Ѿ������ʹ�
*/
void depthFirstSearch(const std::vector<int> *g, int n);

#endif // !_GRAPHSEARCH