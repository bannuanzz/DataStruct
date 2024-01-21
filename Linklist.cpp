#include <iostream>
using namespace std;

struct LinkNode
{
    int data;
    LinkNode *next;
    LinkNode() : next(NULL) {}
    LinkNode(int data) : data(data), next(NULL) {}
};

class Linklist
{
public:
    LinkNode *head;
    Linklist();
    ~Linklist();
    void CreateListF(int a[], int n);
    void CreateListR(int a[], int n);
    void Add(int e);
    LinkNode *geti(int i);
    int Getlength();
    bool GetElem(int i, int e);
    bool SetElem(int i, int e);
    int GetNo(int e);
    bool Insert(int i, int e);
    bool Delete(int i);
    void Displist();
};

int Middle1(Linklist &L); // 遍历链表1.5躺getlength+0.5
int Middle2(Linklist &L); // 遍历链表一趟
int Maxcount(Linklist &L);
void DelMaxNode(Linklist &L);
void Reverse1(Linklist &L);
void Reverse2(Linklist &L);
void Split(Linklist &L, Linklist &A, Linklist &B);
void Merge2(Linklist &A, Linklist &B, Linklist &C);
void Commnodes(Linklist &A, Linklist &B, Linklist &C);
Linklist::Linklist()
{
    head = new LinkNode();
}

Linklist::~Linklist()
{
    LinkNode *pre, *p;
    pre = head;
    p = pre->next;
    while (p != NULL)
    {
        delete pre;
        pre = p;
        p = p->next;
    }
    delete pre;
}
// 头插法
void Linklist::CreateListF(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        LinkNode *s = new LinkNode(a[i]);
        s->next = head->next;
        head->next = s;
    }
}
// 尾插法
void Linklist::CreateListR(int a[], int n)
{
    LinkNode *s, *r;
    r = head;
    for (int i = 0; i < n; i++)
    {
        s = new LinkNode(a[i]);
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

LinkNode *Linklist::geti(int i)
{
    if (i < -1)
        return NULL;
    LinkNode *p = head;
    int j = -1;
    while (j < i && p != NULL)
    {
        j++;
        p = p->next;
    }
    return p;
}

void Linklist::Add(int e)
{
    LinkNode *s = new LinkNode(e);
    LinkNode *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = s;
}

int Linklist::Getlength()
{
    LinkNode *p = head;
    int cnt = 0;
    while (p->next != NULL)
    {
        cnt++;
        p = p->next;
    }
    return cnt;
}

bool Linklist::GetElem(int i, int e)
{
    if (i < 0)
        return false;
    LinkNode *p = geti(i);
    if (p != NULL)
    {
        e = p->data;
        return true;
    }
    else
    {
        return false;
    }
}

bool Linklist::SetElem(int i, int e)
{
    if (i < 0)
        return false;
    LinkNode *p = geti(i);
    if (p != NULL)
    {
        p->data = e;
        return true;
    }
    else
    {
        return false;
    }
}

int Linklist::GetNo(int e)
{
    int j = 0;
    LinkNode *p = head;
    while (p->next != NULL && p->data != e)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
    {
        return -1;
    }
    else
    {
        return j;
    }
}

bool Linklist::Insert(int i, int e)
{
    if (i < 0)
        return false;
    LinkNode *p = geti(i - 1);
    if (p != NULL)
    {
        LinkNode *s = new LinkNode(e);
        s->next = p->next;
        p->next = s;
        return true;
    }
}

bool Linklist::Delete(int i)
{
    if (i < 0)
        return false;
    LinkNode *p = geti(i - 1);
    if (p != NULL)
    {
        LinkNode *q = p->next;
        if (q != NULL)
        {
            p->next = q->next;
            delete q;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
void Linklist::Displist()
{
    LinkNode *p = head;
    p = p->next;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int Middle1(Linklist &L)
{
    int j = 1;
    int n = L.Getlength();
    LinkNode *p = L.head->next;
    while (j <= (n - 1) / 2)
    {
        j++;
        p = p->next;
    }
    return p->data;
}

int Middle2(Linklist &L)
{
    LinkNode *slow = L.head->next;
    LinkNode *fast = L.head->next;
    while (fast != NULL && slow != NULL)
    {
        if (fast->next == NULL || fast->next->next == NULL)
            return slow->data;
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int Maxcount(Linklist &L)
{
    int cnt = 1;
    LinkNode *p = L.head->next;
    int maxe = p->data;
    while (p->next != NULL)
    {
        if (p->next->data > maxe)
        {
            maxe = p->next->data;
            cnt = 1;
        }
        else if (p->next->data == maxe)
            cnt++;
        p = p->next;
    }
    return cnt;
}

void DelMaxNode(Linklist &L)
{
    LinkNode *p = L.head->next;
    int maxe = p->data;
    while (p->next != NULL)
    {
        if (p->next->data > maxe)
            maxe = p->next->data;
        p = p->next;
    }
    LinkNode *pre = L.head;
    p = pre->next;
    while (p != NULL)
    {
        if (p->data == maxe)
        {
            pre->next = p->next;
            delete p;
            p = pre->next;
        }
        else
        {
            pre = pre->next;
            p = pre->next;
        }
    }
}

void Reverse1(Linklist &L)
{
    LinkNode *p = L.head->next;
    L.head->next = NULL;
    LinkNode *q = p;
    while (p != NULL)
    {
        q = p->next;
        p->next = L.head->next;
        L.head->next = p;
        p = q;
    }
}

void Reverse2(Linklist &L)
{
    LinkNode *p = L.head->next, *q, *r;
    if (p == NULL)
        return;
    q = p->next;
    if (q == NULL)
        return;
    r = q->next;
    if (r == NULL)
    {
        L.head->next = q;
        q->next = p;
        p->next = NULL;
        return;
    }
    p->next = NULL;
    while (r != NULL)
    {
        q->next = p;
        p = q;
        q = r;
        r = r->next;
    }
    q->next = p;
    L.head->next = q;
}

void Split(Linklist &L, Linklist &A, Linklist &B)
{
    LinkNode *p = L.head->next, *q;
    LinkNode *r = A.head;
    while (p != NULL)
    {
        r->next = p;
        r = p;
        p = p->next;
        if (p != NULL)
        {
            q = p->next;
            p->next = B.head->next;
            B.head->next = p;
            p = q;
        }
    }
    r->next = NULL;
}

void Merge2(Linklist &A, Linklist &B, Linklist &C)
{
    LinkNode *p = A.head->next;
    LinkNode *q = B.head->next;
    LinkNode *r = C.head;
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            r->next = p;
            r = p;
            p = p->next;
        }
        else
        {
            r->next = q;
            r = q;
            q = q->next;
        }
    }
    r->next = NULL;
    if (p != NULL)
        r->next = p;
    if (q != NULL)
        r->next = q;
}
void Commnodes(Linklist &A, Linklist &B, Linklist &C)
{
    LinkNode *p = A.head->next;
    LinkNode *q = B.head->next;
    LinkNode *r = C.head;
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
            p = p->next;
        else if (q->data < p->data)
            q = q->next;
        else
        {
            LinkNode *s = new LinkNode(p->data);
            r->next = s;
            r = s;
            p = p->next;
            q = q->next;

        }
    }
}
int main()
{
}
