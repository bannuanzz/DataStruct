#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXV = 100;
const int INF = 0x3f3f3f3f;
class MatGraph
{
public:
    int edges[MAXV][MAXV];
    int n, e;
    string vexs[MAXV];
    void CreateMatGraph(int a[][MAXV], int n, int e)
    {
        this->n = n;
        this->e = e;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                this->edges[i][j] = a[i][j];
            }
        }
    }
    void DispMatGraph()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (edges[i][j] = INF)
                    cout << edges[i][j];
        }
    }
};

struct ArcNode
{
    int adjvex;
    int weight;
    ArcNode *nextarc;
};
struct HNode
{
    string info;
    ArcNode *firstarc;
};
class AdjGraph
{
public:
    HNode adjlist[MAXV];
    int n, e;
    AdjGraph()
    {
        for (int i = 0; i < MAXV; i++)
            adjlist[i].firstarc = NULL;
    }
    ~AdjGraph()
    {
        ArcNode *pre, *p;
        for (int i = 0; i < n; i++)
        {
            pre = adjlist[i].firstarc;
            if (pre != NULL)
            {
                p = pre->nextarc;
                while (p != NULL)
                {
                    delete pre;
                    pre = p;
                    p = p->nextarc;
                }
                delete pre;
            }
        }
    }
    void CreateAdjGraph(int a[][MAXV], int n, int e)
    {
        ArcNode *p;
        this->n = n;
        this->e = e;
        for (int i = 0; i < n; i++)
            for (int j = n - 1; j > 0; j--)
                if (a[i][j] != 0 && a[i][j] != INF)
                {
                    p = new ArcNode();
                    p->adjvex = j;
                    p->weight = a[i][j];
                    p->nextarc = adjlist[i].firstarc;
                    adjlist[i].firstarc = p;
                }
    }

    void FindaPath11(AdjGraph &G, int u, int v, vector<int> path)
    {
        visited[u] = 1;
        path.push_back(u);
        if (u == v)
        {
            for (int i = 0; i < path.size(); i++)
                cout << path[i];
            return;
        }
        ArcNode *p = G.adjlist[u].firstarc;
        while (p != NULL)
        {
            int w = p->adjvex;
            if (visited[w] == 0)
                FindaPath11(G, w, v, path);
            p = p->nextarc;
        }
    }

    void FindallPath11(AdjGraph &G, int u, int v, vector<int> path)
    // 被FindallPath1调用
    {
        visited[u] = 1;
        path.push_back(u); // 顶点u加入到路径中
        if (u == v)        // 找到一条路径后输出并返回
        {
            for (int i = 0; i < path.size(); i++)
                printf("  %d", path[i]);
            printf("\n");
            visited[u] = 0; // 回溯,重置visited[u]为0
            return;
        }
        ArcNode *p = G.adjlist[u].firstarc;
        while (p != NULL)
        {
            int w = p->adjvex;                // 找到u的邻接点w
            if (visited[w] == 0)              // 若顶点w没有访问
                FindallPath11(G, w, v, path); // 从w出发继续查找
            p = p->nextarc;
        }
        visited[u] = 0; // 回溯,重置visited[u]为0
    }
};
int Degree1(AdjGraph &G, int v)
{
    int d = 0;
    ArcNode *p = G.adjlist[v].firstarc;
    while (p != NULL)
    {
        d++;
        p = p->nextarc;
    }
    return d;
}
vector<int> Degree2(AdjGraph &G, int v)
{
    vector<int> ans = {0, 0};
    ArcNode *p = G.adjlist[v].firstarc;
    while (p != NULL)
    {
        ans[0]++;
        p = p->nextarc;
    }
    for (int i = 0; i < G.n; i++)
    {
        p = G.adjlist[i].firstarc;
        while (p != NULL)
        {
            if (p->adjvex == v)
            {
                ans[1]++;
                break;
            }
        }
    }
    return ans;
}
int visited[MAXV];
void DFS(AdjGraph &G, int v)
{
    cout << v << " ";
    visited[v] = 1;
    ArcNode *p = G.adjlist[v].firstarc;
    while (p != NULL)
    {
        int w = p->adjvex;
        if (visited[w] == 0)
            DFS(G, w);
        p = p->nextarc;
    }
}

void BFS(AdjGraph &G, int v)
{
    int visited[MAXV] = {0};
    queue<int> qu;
    cout << v << " ";
    visited[v] = 1;
    qu.push(v);
    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        ArcNode *p = G.adjlist[u].firstarc;
        while (p != NULL)
        {
            if (visited[p->adjvex] == 0)
            {
                cout << p->adjvex << " ";
                visited[p->adjvex] = 1;
                qu.push(p->adjvex);
            }
            p = p->nextarc;
        }
    }
}
// int a[100];
// int main()
// {
//     for (int i = 0; i < 100; i++)
//     {
//         cout << a[i];
//     }
// }

bool HasPath1(AdjGraph &G, int u, int v)
{
    visited[u] = 1;
    ArcNode *p = G.adjlist[u].firstarc;
    while (p != NULL)
    {
        int w = p->adjvex;
        if (w == v)
            return true;
        else if (visited[w] == 0)
        {
            if (HasPath1(G, w, v))
                return true;
        }
        p = p->nextarc;
    }
}

struct QNode // 队列元素类型
{
    int v;                // 顶点编号
    int dis;              // 源点到当前顶点的最短路径长度
    QNode() {}            // 构造函数
    QNode(int v, int dis) // 重载构造函数
    {
        this->v = v;
        this->dis = dis;
    }
};
int Shortdist(AdjGraph &G, int u, int v) // 求u到v的最短路径长度
{
    int visited[MAXV]; // 访问标记数组
    memset(visited, 0, sizeof(visited));
    queue<QNode> qu;      // 定义一个队列qu
    visited[u] = 1;       // 置已访问标记
    qu.push(QNode(u, 0)); // 起始点u(距离为0)进队
    while (!qu.empty())   // 队不空循环
    {
        QNode e = qu.front();
        qu.pop();         // 出队一个元素e
        if (e.v == v)     // 找到顶点v
            return e.dis; // 返回u到v的最短路径长度
        ArcNode *p = G.adjlist[e.v].firstarc;
        while (p != NULL)
        {
            int w = p->adjvex;   // 找到u的邻接点w
            if (visited[w] == 0) // 若顶点w没有访问
            {
                visited[u] = 1;               // 置已访问标记
                qu.push(QNode(w, e.dis + 1)); // 邻接点w进队
            }
            p = p->nextarc;
        }
    }
    return INF; // 没有路径的情况
}
int Shortdist2(AdjGraph &G, int u, int v)
// 解法2：求u到v的最短路径长度
{
    int visited[MAXV]; // 访问标记数组
    memset(visited, 0, sizeof(visited));
    int ans = 0;        // 存放最短路径长度(初始时为0)
    queue<int> qu;      // 定义一个队列qu
    visited[u] = 1;     // 置已访问标记
    qu.push(u);         // 起始点u进队
    while (!qu.empty()) // 队不空循环
    {
        int n = qu.size();          // 求队列qu中元素个数n
        for (int i = 0; i < n; i++) // 循环n次
        {
            u = qu.front();
            qu.pop();       // 出队一个顶点u
            if (u == v)     // 找到顶点v
                return ans; // 返回u到v的最短路径长度
            ArcNode *p = G.adjlist[u].firstarc;
            while (p != NULL)
            {
                int w = p->adjvex;   // 找到u的邻接点w
                if (visited[w] == 0) // 若顶点w没有访问
                {
                    visited[w] = 1; // 置已访问标记
                    qu.push(w);     // 邻接点w进队
                }
                p = p->nextarc;
            }
        }
        ans++; // 一层的顶点扩展后ans增1
    }
    return INF; // 没有路径的情况
}

void Prim(MatGraph g, int v) // Prim算法输出的最小生树
{
    int lowcost[MAXV];            // 建立数组lowcost
    int closest[MAXV];            // 建立数组closest
    for (int i = 0; i < g.n; i++) // 给lowcost[]和closest[]置初值
    {
        lowcost[i] = g.edges[v][i];
        closest[i] = v;
    }
    for (int i = 1; i < g.n; i++) // 找出(n-1)个顶点
    {
        int min = INF;
        int k = -1;                   // k记录最近顶点的编号
        for (int j = 0; j < g.n; j++) // 在(V-U)中找出离U最近的顶点k
            if (lowcost[j] != 0 && lowcost[j] < min)
            {
                min = lowcost[j];
                k = j;
            }
        cout << "  边(" << closest[k] << "," << k << "),权为" << min << endl;
        lowcost[k] = 0;               // 标记k已经加入U
        for (int j = 0; j < g.n; j++) // 修改数组lowcost和closest
            if (lowcost[j] != 0 && g.edges[k][j] < lowcost[j])
            {
                lowcost[j] = g.edges[k][j];
                closest[j] = k;
            }
    }
}
struct Edge // 边向量元素类型
{
    int u;                    // 边的起始顶点
    int v;                    // 边的终止顶点
    int w;                    // 边的权值
    Edge(int u, int v, int w) // 构造函数
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
    bool operator<(const Edge &s) const // 重载<运算符
    {
        return w < s.w; // 用于按w递增排序
    }
};
void Kruskal(MatGraph &g) // Kruskal算法输出最小生成树
{
    int vset[MAXV];               // 建立数组vset
    vector<Edge> E;               // 建立存放所有边的向量E
    for (int i = 0; i < g.n; i++) // 由图的邻接矩阵g产生边向量E
        for (int j = 0; j < g.n; j++)
            if (g.edges[i][j] != 0 && g.edges[i][j] != INF && i < j)
                E.push_back(Edge(i, j, g.edges[i][j]));
    sort(E.begin(), E.end()); // 对E按权值递增排序
    for (int i = 0; i < g.n; i++)
        vset[i] = i; // 初始化辅助数组
    int k = 1;       // k是当前构造生成树第几条边,初值为1
    int j = 0;       // E中边的下标,初值为0
    while (k < g.n)  // 生成的边数小于n时循环
    {
        int u1 = E[j].u;
        int v1 = E[j].v; // 取一条边的起始和终止顶点
        int sn1 = vset[u1];
        int sn2 = vset[v1]; // 分别得到两个顶点所属的集合编号
        if (sn1 != sn2)     // 两顶点属不同集合,取该边
        {
            cout << "  边(" << u1 << "," << v1 << "),权为" << E[j].w << endl;
            k++;                          // 生成边数增1
            for (int i = 0; i < g.n; i++) // 两个集合统一编号
                if (vset[i] == sn2)       // 集合编号为sn2的改为sn1
                    vset[i] = sn1;
        }
        j++; // 扫描下一条边
    }
}

void Dijkstra(MatGraph &g, int v)
{
    int dist[MAXV];
    int path[MAXV];
    int S[MAXV];
    for (int i = 0; i < g.n; i++)
    {
        dist[i] = g.edges[v][i];
        S[i] = 0;
        if (g.edges[v][i] != 0 && g.edges[v][i] < INF)
            path[i] = v;
        else
            path[i] = -1;
    }
    S[v] = 1;
    int mindis, u = -1;
    for (int i = 0; i < g.n - 1; i++)
    {
        mindis = INF;
        for (int j = 0; j < g.n; j++)
            if (S[j] == 0 && dist[j] < mindis)
            {
                u = j;
                mindis = dist[j];
            }
        S[u] = 1;
        for (int j = 0; j < g.n; j++)
        {
            if (S[j] == 0)
            {
                if (g.edges[u][j] < INF && dist[u] + g.edges[u][j] < dist[j])
                {
                    dist[j] = dist[u] + g.edges[u][j];
                    path[j] = u;
                }
            }
        }
        // diplay()
    }
}
void Floyd(MatGraph &g) // Floyd求多源最短路径
{
    int A[MAXV][MAXV];            // 建立A数组
    int path[MAXV][MAXV];         // 建立path数组
    for (int i = 0; i < g.n; i++) // 给数组A和path置初值]
        for (int j = 0; j < g.n; j++)
        {
            A[i][j] = g.edges[i][j];
            if (i != j && g.edges[i][j] < INF)
                path[i][j] = i; // i和j顶点之间有一条边时
            else
                path[i][j] = -1; // i和j顶点之间没有一条边时
        }
    for (int k = 0; k < g.n; k++) // 求Ak[i][j]
    {
        for (int i = 0; i < g.n; i++)
            for (int j = 0; j < g.n; j++)
                if (A[i][j] > A[i][k] + A[k][j])
                {
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = path[k][j]; // 修改最短路径
                }
    }
    // Dispath(A, path, g.n); // 输出最短路径和长度
}
