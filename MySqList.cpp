#include <iostream>
using namespace std;
// template <typename T>

const int initcap;
class Sqlist
{
public:
    int *data;
    int capacity;
    int length;
    void recap(int newcap);
    void CreateList(int a[], int n);
    Sqlist();
    Sqlist(const Sqlist &s);
    void Add(int e);
    int Getlength();
    bool GetElem(int i, int &e);
    bool SetElem(int i, int e);
    int GetNo(int e);
    bool Insert(int i, int e);
    bool Delete(int i);
    void Display();
};

void Reverse(Sqlist &L);
bool Deletek(Sqlist &L, int i, int k);
void DeleteX1(Sqlist &L, int x); // 整体建表法
void DeleteX2(Sqlist &L, int x); // 元素移动法
void DeleteX3(Sqlist &L, int x); // 区间划分法
void Merge2(Sqlist a, Sqlist b, Sqlist &C);
int Middle(Sqlist A, Sqlist B);
void Sqlist::recap(int newcap)
{
    if (newcap <= 0)
        return;
    int *olddata = data;
    data = new int[newcap];
    capacity = newcap;
    for (int i = 0; i < length; i++)
        data[i] = olddata[i];
    delete[] olddata;
}

void Sqlist::CreateList(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (length == capacity)
            recap(2 * length);
        data[length] = a[i];
        length++;
    }
}

Sqlist::Sqlist()
{
    data = new int[initcap];
    capacity = initcap;
    length = 0;
}

Sqlist::Sqlist(const Sqlist &s)
{
    capacity = s.capacity;
    length = s.length;
    data = new int[capacity];
    for (int i = 0; i < length; i++)
        data[i] = s.data[i];
}

int Sqlist::Getlength()
{
    return length;
}

void Sqlist::Add(int e)
{
    if (length == capacity)
        recap(2 * length);
    data[length] = e;
    length++;
}

bool Sqlist::GetElem(int i, int &e)
{
    if (i < 0 || i >= length)
        return false;
    e = data[i];
    return true;
}

bool Sqlist::SetElem(int i, int e)
{
    if (i < 0 || i > length)
        return false;
    data[i] = e;
    return true;
}

int Sqlist::GetNo(int e)
{
    int i = 0;
    while (i < length && data[i] != e)
        i++;
    if (i >= length)
        return -1;
    else
        return i;
}

bool Sqlist::Insert(int i, int e)
{
    if (i < 0 || i > length)
        return false;
    if (length == capacity)
        recap(2 * length);
    for (int j = length; j > i; j--)
        data[j] = data[j - 1];
    data[i] = e;
    length++;
    return true;
}

bool Sqlist::Delete(int i)
{
    if (i < 0 || i >= length)
        return false;
    for (int j = i; j < length; j++)
        data[j] = data[j + 1];
    length--;

    if (capacity > initcap && length <= capacity / 4)
        recap(capacity / 2);
    return true;
}
void Sqlist::Display()
{
    for (int i = 0; i < length; i++)
        cout << data[i] << " ";
    cout << endl;
}
void Reverse(Sqlist &L)
{
    int i = 0;
    int j = L.length - 1;
    while (i < j)
    {
        swap(L.data[i], L.data[j]);
        i++;
        j--;
    }
}

bool Deletek(Sqlist &L, int i, int k)
{
    if (i < 0 || k < 1 || i + k < 1 || i + k > L.length)
        return;
    for (int j = i + k; j < L.length; j++)
    {
        L.data[j - k] = L.data[j];
    }
    L.length -= k;
    return true;
}

void DeleteX1(Sqlist &L, int x)
{
    int k = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] != x)
        {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
}

void DeleteX2(Sqlist &L, int x)
{
    int k = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] != x)
            L.data[i - k] = L.data[i];
        else
            k++;
    }
    L.length -= k;
}

void DeleteX3(Sqlist &L, int x)
{
    int i = -1, j = 0;
    while (j < L.length)
    {
        if (L.data[i] != x)
        {
            i++;
            if (i != j)
                swap(L.data[i], L.data[j]);
        }
        j++;
    }
    L.length = i + 1;
}

void Merge2(Sqlist A, Sqlist B, Sqlist &C)
{
    int i = 0, j = 0;
    while (i < A.length && j < B.length)
    {
        if (A.data[i] < B.data[j])
        {
            C.Add(A.data[i]);
            i++;
        }
        else
        {
            C.Add(B.data[i]);
            j++;
        }
    }
    while (i < A.length)
    {
        C.Add(A.data[i]);
    }
    while (j < B.length)
    {
        C.Add(B.data[j]);
        j++;
    }
}

int Middle(Sqlist A, Sqlist B)
{
    int i = 0, j = 0;
    int k = 0; // the times of merge //when the time equal n, it is middle
    while (i < A.length && j < B.length)
    {
        k++;
        if (A.data[i] < B.data[j])
        {
            if (k == A.length)
                return A.data[j];
            i++;
        }
        else
        {
            if (k == B.length)
                return B.data[j];
            j++;
        }
    }
}
int main()
{
}