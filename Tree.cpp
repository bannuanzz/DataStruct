#include <iostream>
#include <vector>
using namespace std;
struct PNode
{
    char data;
    int parent;
    PNode(char d, int p)
    {
        data = d;
        parent = p;
    }
    int Level(vector<PNode> t, int i)
    {
        if (i < 0 || i >= t.size())
            return 0;
        int cnt = 1;
        while (t[i].parent != -1)
        {
            cnt++;
            i = t[i].parent;
        }
        return cnt;
    }
};
int main()
{
}
