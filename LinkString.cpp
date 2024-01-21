#include <iostream>
using namespace std;
struct LinkNode
{
    char data;
    LinkNode *next;
    LinkNode() {}
    LinkNode(char c) : data(c), next(NULL) {}
};
class LinkString
{

public:
    LinkNode *head;
    int length;
    LinkString &InsStr(int i, LinkString &t)
    {
        static LinkString s;
        if (i < 0 || i > length)
            return s;
        LinkNode *p = head->next;
        LinkNode *p1 = t.head->next;
        LinkNode *r = s.head, *q;
        for (int k = 0; k < i; k++)
        {
            q = new LinkNode(p1->data);
            r->next = q;
            r = q;
            p = p->next;
        }
        while (p1 != NULL)
        {
            q = new LinkNode(p1->data);
            r->next = q;
            r = q;
            p1 = p1->next;
        }
        while (p != NULL)
        {
            q = new LinkNode(p->data);
            r->next = q;
            r = q;
            p = p->next;
        }
        s.length = length + t.length;
        r->next = NULL;
        return s; 
    }
} int main()
{
}