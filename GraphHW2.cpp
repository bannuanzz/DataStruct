#include <iostream>
#include <vector>

// 使用vector的vector来表示邻接表
std::vector<std::vector<int>> adjList;

// 访问标记数组
std::vector<bool> visited;

// DFS函数
void DFS(int vertex)
{
    // 标记当前顶点为已访问
    visited[vertex] = true;
    std::cout << vertex << " ";

    // 遍历当前顶点的邻接表
    for (int i = 0; i < adjList[vertex].size(); ++i)
    {
        int adjacentVertex = adjList[vertex][i];
        if (!visited[adjacentVertex])
        {
            DFS(adjacentVertex); // 对未访问的相邻顶点递归调用DFS
        }
    }
}

int main()
{
    // 初始化图的顶点数和边数
    int nVertices = 7;
    adjList.resize(nVertices);
    visited.resize(nVertices, false);

    // 添加边，构造邻接表
    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[1].push_back(2);
    adjList[2].push_back(4);
    adjList[2].push_back(3);
    adjList[3].push_back(4);
    adjList[4].push_back(0);

    // 从顶点0开始DFS
    DFS(0);

    return 0;
}
