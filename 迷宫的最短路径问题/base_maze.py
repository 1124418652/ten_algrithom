"""
题目分析：
图中的最短路径问题，有两种类型：
1、图中所有边的权重都是1，使用广度优先搜索得到的就是最短路径
2、图中不同边的权重不同，弗洛伊德算法（可以解决多源路径问题）
   对于初始路径 u->v，比它更短的路径只能是 u->k->v, u->...->v
迷宫中的最短路径问题，和图中的最短路径问题一样，使用广度优先
白能力进行解决
"""

import sys

def min_road(maze):
    """
    输入地图，输出从迷宫地图的入口到出口的最短路径
    """
    rows = len(maze)
    cols = len(maze[0])
    dcol = [0, 1, 0, -1]    # drow,dcol 表示当前节点进入下一节点该怎么走
    drow = [1, 0, -1, 0]
    visit = []    # 与迷宫相同大小的数组，存储每个节点是第几次访问到
    for row in range(rows):
        visit.append([0] * cols)       # 先对 visit 进行初始化
    
    begin = [0, 0]
    end = [0, 0]
    for row in range(rows):    # 需要先找到 begin 和 end 的位置
        for col in range(cols):
            if maze[row][col] == '2':
                begin[0], begin[1] = row, col
            if maze[row][col] == '3':
                end[0], end[1] = row, col
    print(begin, end)
                
    deque = []      # 用列表表示队列，deque.append(),  deque.pop(0)
    deque.append(begin)
    
    while len(deque) > 0:    # 当队列非空
        currNode = deque.pop(0)    # 删除并返回首元素
        if currNode == end:  # 如果已经访问到了最后一个节点，就终止循环
            break
        for i in range(4):   # 分别获取当前节点的四个子节点的坐标
            row = currNode[0] + drow[i] 
            col = currNode[1] + dcol[i]
            if row >= 0 and row < rows and col >= 0 and col < cols and visit[row][col] == 0 and (maze[row][col] == '1' or maze[row][col] == '3'):
                deque.append([row, col])
                # 更新每个子节点是第几次访问到的
                visit[row][col] = 1 + visit[currNode[0]][currNode[1]]
    print(visit)
    return visit[end[0]][end[1]]

if __name__ == '__main__':
    
    while True:
        
        line1 = sys.stdin.readline().strip() # 第一行输入迷宫的行数和列数
        rows, cols = list(map(int, line1.split()))
        
        if rows > 100 or cols > 100 or rows <= 0 or cols <=0:
            continue
        
        maze = []
        for row in range(rows):
            tmp = sys.stdin.readline().strip()
            maze.append([x for x in tmp])   # 在地图中创建迷宫的每一行
        
        print(min_road(maze))    # 打印最短路径