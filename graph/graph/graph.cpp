// graph.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "graphSearch.h"

using namespace std;

const int numNodes = 100;
vector<int> g[numNodes];

int main()
{
	int i;
	int u, v;     // ��ǰ�ڵ��ָ��Ľڵ�
	for (i = 0; i < 10; ++i)
	{
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	depthFirstSearch(g, 10);
	system("pause");
    return 0;
}

