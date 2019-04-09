#include "stdafx.h"
#include "graphSearch.h"


void breadthFirstSearch(const std::vector<int> *g, int n)
{
	int i;                     // ���ڱ����ڵ��ѭ������
	int *nodeSearched = new int[n];  // ���ڱ���ÿ���ڵ��Ƿ��Ѿ������ʵ�����

	for (i = 0; i < n; ++i)
	{
		nodeSearched[i] = 0;
	}

	for (i = 0; i < n; ++i)    // ��Ϊͼ�����ǶϿ��ģ�������Ҫ�����нڵ�Ϊ��ʼ�ڵ����
	{
		std::deque<int> tmp;   // ���ڼ�¼�м�ڵ����˳���
		if (nodeSearched[i] != 0)     // �����жϸýڵ��Ƿ��Ѿ������ʹ�
			continue;
		std::cout << i << std::endl;
		tmp.push_back(i);
		nodeSearched[i] += 1;  // ����ǰ�ڵ�ķ��ʴ���+1

		while (!tmp.empty())
		{
			int currNode = tmp.front();
			for (size_t j = 0; j < g[currNode].size(); ++j)
			{
				if (nodeSearched[g[currNode][j]] == 0)          // �ýڵ���ǰδ�����ʵ���
				{
					std::cout << g[currNode][j] << std::endl;   
					tmp.push_back(g[currNode][j]);
					nodeSearched[g[currNode][j]] += 1;          // ���ýڵ�ķ��ʴ���+1
				}
			}
			tmp.pop_front();
		}
	}
}

void depthFirstSearch(const std::vector<int> *g, int n)
{
	int i;        // ���ڱ����ڵ��ѭ������
	int *nodeSearched = new int[n];
	for (i = 0; i < n; ++i)
	{
		nodeSearched[i] = 0;
	}

	for (i = 0; i < n; ++i)
	{
		std::stack<int> tmp;      // ���ڱ����м���������ջ

		if (nodeSearched[i] != 0)
			continue;

		tmp.push(i);              // ��ͷ�ڵ���ջ
		nodeSearched[i] += 1;     // ͷ�ڵ�ķ��ʴ�����1

		while (!tmp.empty())
		{
			int currNode = tmp.top();      // ��������������ȷ��ʵĽڵ��Ƚ��������������������ʱ����ʵ��Ľڵ��Ƚ�������
			// �����һ����������������ͬ����������������ڷ��ʵ�����Ҫ��Ľڵ�֮���������
		    // ���������������ֻ���λ��ջ����Ԫ��
			std::cout << currNode << std::endl;
			tmp.pop();     // ɾ��ջ��Ԫ����һ��һ��Ҫλ����ջ�м�������ڵ�֮ǰ  
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