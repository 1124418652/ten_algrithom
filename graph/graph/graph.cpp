// graph.cpp : 定义控制台应用程序的入口点。
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
	int u, v;     // 当前节点和指向的节点
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

