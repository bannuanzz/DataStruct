#include <iostream>
using namespace std;
const int MaxSize = 100;
struct LinkNode
{
    int data;
    LinkNode *next;
    LinkNode() : next(NULL) {}
    LinkNode(int x) : data(x), next(NULL) {}
};
class LinkStack
{
public:
    LinkNode *head;
    LinkStack()
    {
        head = new LinkNode();
    }
    ~LinkStack()
    {
        LinkNode *pre = head, *p = pre->next;
        while (p != NULL)
        {
            delete pre;
            pre = p;
            p = p->next;
        }
        delete pre;
    }
    bool empty()
    {
        return head->next == NULL;
    }
    bool push(int e)
    {
        LinkNode *p = new LinkNode(e);
        p->next = head->next;
        head->next = p;
        return true;
    }
    bool pop(int &e)
    {
        LinkNode *p;
        if (head->next = NULL)
            return false;
        p = head->next;
        e = head->data;
        head->next = p->next;
        delete p;
        return true;
    }
    bool gettop(int &e)
    {
        LinkNode *p;
        if (head->next == NULL)
            return false;
        p = head->next;
        e = p->data;
        return true;
    }
};
void Reverse(LinkStack &st)
{
    int a[MaxSize];
    int i = 0, e;
    while (!st.empty())
    {
        st.pop(e);
        a[i] = e;
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        st.push(a[j]);
    }
}

int main()
{
}