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
class CDLinkList
{
public:
    DLinkNode *dhead;
    CDLinkList()
    {
        dhead = new DLinkNode();
        dhead->next = dhead;
        dhead->prior = dhead;
    }
    ~CDLinkList()
    {
        DLinkNode *pre, *p;
        pre = dhead;
        p = pre->next;
        while (p != dhead)
        {
            delete pre;
            pre = p;
            p = p->next;
        }
        delete pre;
    }
};
void Comb(CDLinkList &A, CDLinkList &B)
{
    DLinkNode *ta = A.dhead->prior;
    DLinkNode *tb = B.dhead->prior;
    ta->next = B.dhead->next;
    B.dhead->next->prior = ta;
    tb->next = A.dhead;
    A.dhead->prior = tb;
    B.dhead->next = B.dhead;
    B.dhead->prior = B.dhead;
}

bool Symm(CDLinkList &L)
{
    bool flag = true;
    DLinkNode *p = L.dhead->next;
    DLinkNode *q = L.dhead->prior;
    while (flag)
    {
        if (p->data != q->data)
            flag = false;
        else
        {
            if (p == q || p == q->prior)
                break;
            q = q->prior;
            p = p->next;
            
        }
    }
}

int main()
{
}