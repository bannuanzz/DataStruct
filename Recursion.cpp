#include <iostream>
int fun(int n)
{
    if (n == 1)
        return 1;
    else
        return fun(n - 1) * n;
}

int Fib(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return Fib(n - 2) + Fib(n - 1);
}

template <typename T>
class LinkNode
{
public:
    T data;
    LinkNode<T> *next;
    LinkNode() : next(NULL) {}
    LinkNode(T d) : data(d), next(NULL) {}
};

int Sum(LinkNode<int> *p)
{
    if (p == NULL)
        return 0;
    else
        return p->data + Sum(p->next);
}

void Hanoi(int n, char x, char y, char z)
{
    if (n == 1)
        cout << n << "from" << x << "to" << z << endl;
    else
    {
        Hanoi(n - 1, x, z, y);
        cout << n << "from" << x << "to" << z << endl;
        Hanoi(n - 1, y, x, z);
    }
}

int Min(int a[], int i)
{
    if (i == 0)
        return a[0];
    else
    {
        int mind = Min(a, i - 1);
        return min(mind, a[i]);
    }
}

void Positive(LinkNode<int> *p)
{
    if (p == NULL)
        return;
    else
    {
        cout << p->data;
        Positive(p->next);
    }
}

void Invert(LinkNode<int> *p)
{
    if (p == NULL)
        return;
    else
    {
        Invert(p->next);
        cout << p->data;
    }
}

LinkNode<int> *Reverse(LinkNode<int> *p)
{
    if (p == NULL)
        return;
    if (p->next == NULL)
        return p;
    else
    {
        LinkNode<int> *np;
        np = Reverse(p->next);
        p->next->next = p;
        p->next = NULL;
        return np;
    }
}

int Sum(double x)
{
    if (x >= 0 && x <= 9)
        return x;
    else
        return Sum(x / 10) + x % 10;
}

double pow(double x, int n)
{
    if (n == 1)
        return x;
    double p = pow(x, n / 2);
    if (n % 2 == 1)
        return x * p * p;
    else
        return p * p;
}