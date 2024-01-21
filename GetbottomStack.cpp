#include <iostream>
using namespace std;
const int MaxSize = 100;
template <typename T>
struct LinkNode
{
    T data;
    LinkNode *next;
    LinkNode() : next(NULL) {}
    LinkNode(T x) : data(x), next(NULL) {}
};

template <typename T>
class STACK
{
public:
    LinkNode<T> *rear;
    STACK() : rear(NULL) {}
    ~STACK()
    {
        if (rear == NULL)
            return;
        LinkNode<T> *pre = rear, *p = pre->next;
        while (p != rear)
        {
            delete pre;
            pre = p;
            p = p->next;
        }
        delete pre;
    }
    bool empty()
    {
        return rear == NULL;
    }
    bool push(T e)
    {
        LinkNode<T> *p = new LinkNode(e);
        if (empty())
        {
            rear = p;
            rear->next = rear;
        }
        else
        {
            p->next = rear->next;
            rear->next = p;
        }
        return true;
    }
    bool pop(T &e)
    {
        LinkNode<T> *p;
        if (empty())
            return false;
        if (rear->next == rear)
        {
            p = rear;
            rear = NULL;
        }
        else
        {
            p = rear->next;
            rear->next = p->next;
        }
        e = p->data;
        delete p;
        return true;
    }
    bool gettop(T &e)
    {
        if (empty())
            return false;
        e = rear->next->data;
        return true;
    }
    T Getbottom()
    {
        if (empty())
            throw "The stack is empty" return rear->data;
    }
}