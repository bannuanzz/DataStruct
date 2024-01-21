#include <iostream>
using namespace std;
struct DLinkNode
{
    int data;
    DLinkNode *next;
    DLinkNode *prior;
    DLinkNode() : next(NULL), prior(NULL) {}
    DLinkNode(int d) : data(d), next(NULL), prior(NULL) {}
};
class DLinkList
{
public:
    DLinkNode *dhead;
    void CreateListF(int a[], int n);
    void CreateListR(int a[], int n);
    bool Insert(int i, int e);
    bool Delete(int i);
    DLinkNode *geti(int i);
};

void DelX(DLinkList &L, int x);
void Swap(DLinkList &L, int x);
void DLinkList::CreateListF(int a[], int n)
{
    DLinkNode *s;
    for (int i = 0; i < n; i++)
    {
        s = new DLinkNode(a[i]);
        s->next = dhead->next;
        if (dhead->next != NULL)
            dhead->next->prior = s;
        dhead->next = s;
        s->prior = dhead;
    }
}

void DLinkList::CreateListR(int a[], int n)
{
    DLinkNode *s, *r;
    r = dhead;
    for (int i = 0; i < n; i++)
    {
        s = new DLinkNode(a[i]);
        r->next = s;
        s->prior = r;
        r = s;
    }
    r->next = NULL;
}
DLinkNode *DLinkList::geti(int i)
{
    if (i < 0)
        return NULL;
    DLinkNode *p = dhead;
    int j = -1;
    while (p != NULL && j != i)
    {
        j++;
        p = p->next;
    }
    return p;
}
bool DLinkList::Insert(int i, int e)
{
    if (i < 0)
        return false;
    DLinkNode *s = new DLinkNode(e);
    DLinkNode *p = geti(i - 1); // geti 见LinkList
    if (p != NULL)
    {
        s->next = p->next;
        if (p->next != NULL)
            p->next->prior = s;
        p->next = s;
        s->prior = p;
        return true;
    }
    else
        return false;
}

bool DLinkList::Delete(int i)
{
    if (i < 0)
        return false;
    DLinkNode *p = geti(i);
    if (p != NULL)
    {
        p->prior->next = p->next;
        if (p->next != NULL)
            p->next->prior = p->prior;
        delete p;
        return true;
    }
}

void DelX(DLinkList &L, int x)
{
    DLinkNode *p = L.dhead;
    while (p != NULL && p->data != x)
    {
        p = p->next;
    }
    if (p != NULL)
    {
        p->prior->next = p->next;
        if (p->next != NULL)
            p->next->prior = p->prior;
        delete p;
    }
}

void Swap(DLinkList &L, int x)
{
    DLinkNode *p = L.dhead->next, *q;
    q = NULL;
    while (p != NULL)
    {
        if (p->data == x)
            q = p;
        p = p->next;
    }
    if (q == NULL || L.dhead->next == q)
    {
        return;
    }
    else
    {
        DLinkNode *pre = q->prior;
        pre->next = q->next;
        if (q->next != NULL)
        {
            q->next->prior = pre;
        }
        pre->prior->next = q;
        q->prior = pre->prior;
        pre->prior = q;
        q->next = pre;
        
    }
}
int main()
{
}