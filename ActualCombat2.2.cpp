#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){};
};

class Solution
{
public:
    ListNode *swapPairs1(ListNode *head)
    {
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *temp = dummyHead;
        while (temp->next != NULL && temp->next->next != NULL)
        {
            ListNode *node1 = temp->next;
            ListNode *node2 = temp->next->next;
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
        }
        return dummyHead->next;
    }
    ListNode *swapPairs2(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *next = head->next;
        head->next = swapPairs2(next->next);
        next->next = head;
        return next;
    }
};
int main()
{
}