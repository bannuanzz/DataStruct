#include <iostream>
#include <stack>
using namespace std;
const int MaxSize = 100;

class STACK
{
    int data[MaxSize];
    int mindata[MaxSize];
    int top;
    int mintop;

public:
    STACK() : top(-1), mintop(-1) {}

private:
    bool minempty()
    {
        return mintop = -1;
    }
    void minpush(int e)
    {
        mintop++;
        mindata[mintop] = e;
    }
    int minpop()
    {
        int x = mindata[mintop];
        mintop--;
        return x;
    }
    int mingettop()
    {
        return mindata[mintop];
    }

public:
    bool empty()
    {
        return top == -1;
    }
    bool push(int x)
    {
        if (top == MaxSize - 1)
            return false;
        if (empty() || x <= Getmin())
            minpush(x);
        top++;
        data[top] = x;
        return true;
    }
    bool pop(int &x)
    {
        if (empty())
            return false;
        x = data[top];
        top--;
        if (x == mingettop())
            minpop();
        return true;
    }
    bool gettop(int &e)
    {
        if (empty())
            return false;
        e = data[top];
        return true;
    }
    int Getmin()
    {
        return mingettop();
    }
};
int main()
{
}