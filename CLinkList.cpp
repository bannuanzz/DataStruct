#include <iostream>
using namespace std;
struct LinkNode
{
    int data;
    LinkNode *next;
    LinkNode() : next(NULL) {}
    LinkNode(int x) : data(x), next(NULL) {}
};

class CLinkList
{
public:
    LinkNode *head;
    CLinkList()
    {
        head = new LinkNode();
        head->next = head;
    }
    ~CLinkList()
    {
        LinkNode *pre, *p;
        pre = head;
        p = pre->next;
        while (p != head)
        {
            delete pre;
            pre = p;
            p = p->next;
        }
        delete pre;
    }
};

int Count(CLinkList &L, int x);

int Count(CLinkList &L, int x)
{
    int cnt = 0;
    LinkNode *p = L.head->next;
    while (p != NULL)
    {
        if (p->data == x)
            cnt++;
        p = p->next;
    }
    return cnt;
}

struct Child
{
    int no;
    Child *next;
    Child(int d) : no(d), next(NULL) {}
};

class Joseph
{
    int n, m;
    Child *first;

public:
    Joseph(int n1, int m1) : n(n1), m(m1) {}
    void CreateList()
    {
        first = new Child(1);
        Child *r = first, *p;
        for (int i = 2; i <= n; i++)
        {
            p = new Child(i);
            r->next = p;
            r = p;
        }
        r->next = first;
    }
    void Jsequence()
    {
        Child *p, *q;
        for (int i = 1; i <= n; i++)
        {
            p = first;
            int j = 1;
            while (j != m)
            {
                j++;
                p = p->next;
            }
            cout << p->no << " ";
            q = p->next;
            p->no = q->no;
            p->next = q->next;
            delete q;
            first = p;
        }
        cout << endl;
    }
};
int main()
{
    int n = 6, m = 3;
    Joseph L(n, m);
    cout << "n="
         << ",m=" << m << " Jsequence:" << endl;
    L.CreateList();
    L.Jsequence();
    
}