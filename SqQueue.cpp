#include <iostream>
using namespace std;
const int MaxSize = 100;
template <typename T>
class SqQueue
{
public:
    T *data;
    int front, rear;
    SqQueue()
    {
        data = new T[MaxSize];
        front = rear = -1;
    }
    ~SqQueue()
    {
        delete[] data;
    }
    bool empty()
    {
        return (front == rear);
    }
    bool push(T e)
    {
        if (rear == MaxSize - 1)
            return false;
        rear++;
        data[rear] = e;
        return true;
    }
    bool pop(T &e)
    {
        if (front == rear)
            return false;
        front++;
        e = data[front];
        return true;
    }
    bool gethead(T &e)
    {
        if (front == rear)
            return false;
        int head = front + 1;
        e = data[head];
        return true;
    }
};