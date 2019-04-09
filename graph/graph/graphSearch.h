#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <stack>

#ifndef _GRAPHSEARCH
#define _GRAPHSEARCH



/*
 图的广度优先遍历
 @params g 存储图的邻接表
 @params n 图中节点的数目
*/
void breadthFirstSearch(const std::vector<int> *g, int n);

/*
 图的深度优先遍历
 @params g 存储图的邻接表
 @params nodeSearched 记录图中的节点是否已经被访问过
*/
void depthFirstSearch(const std::vector<int> *g, int n);

#endif // !_GRAPHSEARCH