#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 4;
int mg[MAX][MAX] = {{0, 1, 0, 0}, {0, 0, 1, 1}, {0, 1, 0, 0}, {0, 0, 0, 0}};
int m = 4;
int n = 4;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
struct Box
{

    int i, j;
    Box *pre;
    Box() {}
    Box(int i1, int j1)
    {
        i = i1, j = j1;
        pre = NULL;
    }
};
bool mgpath(int xi, int yi, int xe, int ye)
{
    Box *b;
    Box *b1;
    queue<Box *> qu;
    qu.push(b);
    mg[xi][yi] = -1;
    while (!qu.empty())
    {
        b = qu.front();
        if (b->i == xe && b->j == ye)
        {
            disppath(qu);
            return true;
        }
        qu.pop();
        for (int di = 0; di < 4; di++)
        {
            int i = b->i + dx[di];
            int j = b->j + dy[di];
            if (i >= 0 && j >= 0 && i < n && j < n && mg[i][j] == 0)
            {
                b1 = new Box(i, j);
                b1->pre = b;
                qu.push(b1);
                mg[i][j] = -1;
            }
        }
    }
    return false;
}
void disppath(queue<Box *> &qu)
{
    vector<Box> apath;
    Box *b;
    b = qu.front();
    while (b != NULL)
    {
        apath.push_back(Box(b->i, b->j));
        b = b->pre;
    }
    for (int i = apath.size() - 1; i >= 0; i--)
    {
        cout << apath[i].i << apath[i].j;
    }
    cout << endl;
}
int main()
{
}