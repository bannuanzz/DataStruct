#include <iostream>
#include <string>
#include <vector>
using namespace std;
void GetNext(string t, int *next)
{
    int j = 0;
    int k = -1;
    next[0] = -1;
    while (j < t.length() - 1)
    {
        if (k == -1 || t[j] == t[k])
        {
            k++;
            j++;
            next[j] = k;
            // if (t[j] == t[k])
            // {
            //     next[j] = next[k];
            // }
            // else
            // {
            //     next[j] = k;
            // }
        }
        else
        {
            k = next[k];
        }
    }
}
int KMP(string s, string t)
{
    int m = s.size();
    int n = s.size();
    int *next = new int[n];
    GetNext(t, next);
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (s[i] == t[j] || j == -1)
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j >= m)
    {
        return i - n;
    }
    else
    {
        return -1;
    }
}
int Partition1(vector<int> &R, int s, int t)
{
    int base = R[s];
    int j = t;
    int i = s;
    while (i < j)
    {
        while (j > i && R[j] > base)
            j--;
        while (i < j && R[i] < base)
            i++;
        if (i != j)
        {
            swap(R[j], R[i]);
        }
    }
    swap(R[j], R[s]);
    return i;
}
void QuickSort(vector<int> &R, int s, int t)
{
    if (s < t)
    {
        int i = Partition1(R, s, t);
        QuickSort(R, s, i - 1);
        QuickSort(R, i + 1, t);
    }
}

// void siftDown(vector<int> &R, int low, int high)
// {
//     int i = low;
//     int j = 2 * i + 1;
//     int temp = R[i];
//     while (j <= high)
//     {
//         if (j < high && R[j] < R[j + 1])
//             j++;
//         if (temp < R[j])
//         {
//             R[i] = R[j];
//             i = j;
//             j = 2 * i + 1;
//         }
//         else
//             break;
//     }
//     R[i] = temp;
// }
// void HeapSort(vector<int> &R, int n)
// {
//     for (int i = n / 2 - 1; i >= 0; i--)
//         siftDown(R, i, n - 1);
//     for (int i = n - 1; i > 0; i--)
//     {
//         swap(R[0], R[i]);
//         siftDown(R, 0, i - 1);
//     }
// }

void siftDown(vector<int> &R, int low, int high)
{
    int i = low;
    int j = 2 * i + 1;
    int temp = R[i];
    while (j <= high)
    {
        if (R[j] < R[j + 1] && j < high)
            j++;
        if (R[j] > temp)
        {
            R[i] = R[j];
            i = j;
            j = i * 2 + 1;
        }
        else
            break;
    }
    R[i] = temp;
}

void HeapSort(vector<int> &R, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        siftDown(R, i, n);
    for (int i = n - 1; i > 0; i--)
    {
        swap(R[0], R[i]);
        siftDown(R, 0, i - 1);
    }
}

struct ArcNode
{
    int weight;
    int adjvex;
    int *nextarc;
};
struct HNode
{
    int *firstarc;
    string info;
};
class Graph
{
    HNode *adjlist[100];
    Graph() { for (int i = 0;; i++) }
};
int visited[100];
void DFS(Graph G, int v)
{
    cout << v;
    
}
int main()
{
}