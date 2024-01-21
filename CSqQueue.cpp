#include <iostream>
using namespace std;
const int MaxSize = 100;
template <typename T>
class CSqQueue
{
public:
    T *data;
    int front, rear;
    CSqQueue()
    {
        data = new T[MaxSize];
        front = rear = 0;
    }
    ~CSqQueue()
    {
        delete[] data;
    }
    bool empty()
    {
        return (front == rear);
    }
    bool push(T e)
    {
        if ((rear + 1) % MaxSize == front)
            return false;
        rear = (rear + 1) % MaxSize;
        data[rear] = e;
        return true;
    }
    bool pop(T &e)
    {
        if (front == rear)
            return false;
        front = (front + 1) % MaxSize;
        e = data[front];
        return true;
    }

    bool gethead(T &e)
    {
        if (front == rear)
            return false;
        int head = (front + 1) % MaxSize;
        e = data[head];
        return true;
    }
    int getlength()
    {
        return (rear - front + MaxSize) % MaxSize;
    }
    bool pushk(CSqQueue<int> &qu, int k, int e)
    {
        int x;
        int n = qu.getlength();
        if (k < 1 || k > n + 1)
            return false;
        if (k <= n)
        {
            for (int i = 1; i <= n; i++)
            {
                if (i == k)
                    qu.push(e);
                qu.pop(x);
                qu.push(x);
            }
        }
        else
            qu.push(e);
        return true;
    }
    bool popk(CSqQueue<int> &qu, int k, int &e)
    {
        int x;
        int n = qu.getlength();
        if (k <= 1 || k > n)
            return false;
        for (int i = 1; i <= n; i++)
        {
            qu.pop(x);
            if (i != k)
                qu.push(x);
            else
                e = x;
        }
        return true;
    }
};
template <typename T>
class CSqQueue1
{
public:
    T *data;
    int front;
    int count;
    CSqQueue1()
    {
        data = new T[MaxSize];
        front = 0;
        count = 0;
    }
    ~CSqQueue1()
    {
        delete[] data;
    }
    bool empty()
    {
        return count == 0;
    }
    bool push(T e)
    {
        if (count == MaxSize)
            return false;
        int rear1 = (front + count) % MaxSize;
        rear1 = (rear1 + 1) % MaxSize;
        data[rear1] = e;
        count++;
        return true;
    }
    bool pop(T &e)
    {
        if (count == 0)
            return false;
        front = (front + 1) % MaxSize;
        e = data[front];
        count--;
        return true;
    }
    bool gethead(T &e)
    {
        if (count == 0)
            return false;
        int head = (front + 1) % MaxSize;
        e = data[head];
        return true;
    }
};
int main()
{
}