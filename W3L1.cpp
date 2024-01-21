#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100;
const int INF = 65535;
class MatGraph
{
public:
    int edges[MAX][MAX];
    int n, e;
    int EdgeID[MAX][MAX];
    int vexs[MAX];
};
vector<int> ID;

int Prim(MatGraph g, int v)
{
    int weight = 0;
    int lowcost[MAX];
    int closest[MAX];
    for (int i = 0; i < g.n; i++)
    {
        lowcost[i] = g.edges[v][i];
        closest[i] = v;
    }

    for (int i = 1; i < g.n; i++)
    {
        int min = INF;
        int k = -1;
        for (int j = 0; j < g.n; j++)
        {
            if (lowcost[j] != 0 && lowcost[j] < min)
            {
                min = lowcost[j];
                k = j;
            }
        }
        weight += lowcost[k];
        ID.push_back(g.EdgeID[k][closest[k]]);
        lowcost[k] = 0;
        for (int j = 0; j < g.n; j++)
        {
            if (lowcost[j] != 0 && g.edges[k][j] < lowcost[j])
            {
                lowcost[j] = g.edges[k][j];
                closest[j] = k;
            }
        }
    }
    return weight;
}

int main()
{
    int Enum;
    int Vnum;
    int minCost;
    MatGraph g;
    cin >> Vnum >> Enum;
    g.n = Vnum;
    g.e = Enum;
    for (int i = 0; i < Vnum; i++)
    {
        for (int j = 0; j < Vnum; j++)
        {
            g.edges[i][j] = INF;
        }
    }
    for (int i = 0; i < Vnum; i++)
    {
        g.edges[i][i] = 0;
    }
    for (int i = 0; i < Enum; i++)
    {
        int ID, Tvec1, Tvec2, weight;
        cin >> ID >> Tvec1 >> Tvec2 >> weight;
        g.edges[Tvec1][Tvec2] = weight;
        g.edges[Tvec2][Tvec1] = weight;
        g.EdgeID[Tvec1][Tvec2] = ID;
        g.EdgeID[Tvec2][Tvec1] = ID;
    }
    minCost = Prim(g, 0);
    cout << minCost << endl;
    sort(ID.begin(), ID.end());
    for (int i = 0; i < (int)ID.size(); i++)
    {
        cout << ID[i] << " ";
    }
}