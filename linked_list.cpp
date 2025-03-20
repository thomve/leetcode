#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *rotateRight(ListNode *head, int k)
{
    if (!head || !head->next || k == 0)
        return head;

    // length of the list
    int length = 1;
    ListNode *tail = head;
    while (tail->next)
    {
        tail = tail->next;
        length++;
    }

    tail->next = head;

    // find the new tail
    k = k % length;
    int stepsToNewTail = length - k;
    ListNode *newTail = head;
    for (int i = 1; i < stepsToNewTail; i++)
    {
        newTail = newTail->next;
    }

    // set the new head
    ListNode *newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}