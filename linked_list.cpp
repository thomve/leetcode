#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Given the head of a linked list, rotate the list to the right by k places.
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

// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
// k is a positive integer and is less than or equal to the length of the linked list.
// If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
// You may not alter the values in the list's nodes, only nodes themselves may be changed.
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (!head || k == 1)
        return head;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prev = dummy, *cur = dummy, *next = dummy;

    int count = 0;
    while (cur->next)
    {
        cur = cur->next;
        count++;
    }

    while (count >= k)
    {
        cur = prev->next;
        next = cur->next;
        for (int i = 1; i < k; i++)
        {
            cur->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = cur->next;
        }
        prev = cur;
        count -= k;
    }

    return dummy->next;
}

class LRUCache
{
private:
    int capacity;
    list<pair<int, int>> cacheList;
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;

    void moveToFront(int key)
    {
        auto it = cacheMap[key];
        cacheList.splice(cacheList.begin(), cacheList, it);
    }

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (cacheMap.find(key) == cacheMap.end())
        {
            return -1;
        }
        moveToFront(key);
        return cacheMap[key]->second;
    }

    void put(int key, int value)
    {
        if (cacheMap.find(key) != cacheMap.end())
        {
            cacheMap[key]->second = value;
            moveToFront(key);
        }
        else
        {
            if (cacheList.size() == capacity)
            {
                auto lru = cacheList.back();
                cacheMap.erase(lru.first);
                cacheList.pop_back();
            }
            cacheList.emplace_front(key, value);
            cacheMap[key] = cacheList.begin();
        }
    }
};