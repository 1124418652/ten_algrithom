#include "stdafx.h"
#include "graphSearch.h"


void breadthFirstSearch(const std::vector<int> *g, int n)
{
	int i;                     // 用于遍历节点的循环变量
	int *nodeSearched = new int[n];  // 用于保存每个节点是否已经被访问的数组

	for (i = 0; i < n; ++i)
	{
		nodeSearched[i] = 0;
	}

	for (i = 0; i < n; ++i)    // 因为图可能是断开的，所以需要以所有节点为起始节点进行
	{
		std::deque<int> tmp;   // 用于记录中间节点访问顺序的
		if (nodeSearched[i] != 0)     // 首先判断该节点是否已经被访问过
			continue;
		std::cout << i << std::endl;
		tmp.push_back(i);
		nodeSearched[i] += 1;  // 将当前节点的访问次数+1

		while (!tmp.empty())
		{
			int currNode = tmp.front();
			for (size_t j = 0; j < g[currNode].size(); ++j)
			{
				if (nodeSearched[g[currNode][j]] == 0)          // 该节点先前未被访问到过
				{
					std::cout << g[currNode][j] << std::endl;   
					tmp.push_back(g[currNode][j]);
					nodeSearched[g[currNode][j]] += 1;          // 将该节点的访问次数+1
				}
			}
			tmp.pop_front();
		}
	}
}

void depthFirstSearch(const std::vector<int> *g, int n)
{
	int i;        // 用于遍历节点的循环变量
	int *nodeSearched = new int[n];
	for (i = 0; i < n; ++i)
	{
		nodeSearched[i] = 0;
	}

	for (i = 0; i < n; ++i)
	{
		std::stack<int> tmp;      // 用于保存中间遍历结果的栈

		if (nodeSearched[i] != 0)
			continue;

		tmp.push(i);              // 将头节点入栈
		nodeSearched[i] += 1;     // 头节点的访问次数加1

		while (!tmp.empty())
		{
			int currNode = tmp.top();      // 广度优先搜索是先访问的节点先进行搜索，深度优先搜索时后访问到的节点先进行搜索
			// 输出这一步与广度优先搜索不同，广度优先搜索是在访问到符合要求的节点之后先输出，
		    // 而深度优先搜索是只输出位于栈顶的元素
			std::cout << currNode << std::endl;
			tmp.pop();     // 删除栈顶元素这一步一定要位于往栈中加入后续节点之前  
			for (size_t j = 0; j < g[currNode].size(); ++j)
			{
				if (nodeSearched[g[currNode][j]] == 0)
				{
					tmp.push(g[currNode][j]);
					nodeSearched[g[currNode][j]] += 1;
				}
			}	
		}
	}
}