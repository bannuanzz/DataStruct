#include <iostream>
using namespace std;
template <typename T>
struct LinkNode
{
    T data;
    LinkNode *next;
    LinkNode() : next(NULL) {}
    LinkNode(T d) : data(d), next(NULL) {}
};
template <typename T>
class LinkQueue
{
public:
    LinkNode<T> *front;
    LinkNode<T> *rear;
    LinkQueue()
    {
        front = NULL;
        rear = NULL;
    }
    ~LinkQueue()
    {
        LinkNode<T> *pre = front, *p;
        if (pre != NULL)
        {
            if (pre == rear)
                delete pre;
            else
            {
                p = pre->next;
                while (p != NULL)
                {
                    delete pre;
                    pre = p;
                    p = p->next;
                }
                delete pre;
            }
        }
    }
    bool empty()
    {
        return rear == NULL;
    }
    bool push(T e)
    {
        LinkNode<T> *p = new LinkNode<T>(e);
        if (rear == NULL)
            front = rear = p;
        else
        {
            rear->next = p;
            rear = p;
        }
        return true;
    }
    bool pop(T &e)
    {
        if (rear == NULL)
            return false;
        LinkNode<T> *p = front;
        if (front == rear)
            front = rear = NULL;
        else
            front = front->next;
        e = p->data;
        delete p;
        return true;
    }
    bool gethead(T &e)
    {
        if (rear == NULL)
            return false;
        e = front->data;
        return true;
    }
};
void Jsequence(int n, int m)
{
    int x;
    LinkQueue<int> qu;
    for (int i = 1; i <= n; i++)
        qu.push(i);
    for (int i = 1; i <= n; i++)
    {
        int j = 1;
        while (j <= m - 1)
        {
            qu.pop(x);
            qu.push(x);
            j++;
        }
        qu.pop(x);
        cout << x << " ";
    }
    cout << endl;
}
int main()
{
}