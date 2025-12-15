#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* removeNthNodeFromTheEnd(ListNode* head, int n){
    int count =0;
    ListNode* mover = head;

    while(mover){
        count++;
        mover = mover -> next;
    }
    if (n > count) return head;

    if (n == count) {
        ListNode* newHead = head->next;
        delete head;
        return newHead;
    }

    int stopPos = count - n - 1;
    mover = head;

    while(stopPos--) mover = mover -> next;
    ListNode* deletedNode = mover->next;
    mover->next = mover->next->next;
    delete deletedNode;

    return head;
    
}



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//  better method
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        while(n--) fast = fast -> next;

        // when we need to remove the head
        if (fast == nullptr) {
            ListNode* deletedNode = head;
            head = head -> next;
            delete deletedNode;
            return head;
        }

        ListNode* slow = head;
        while(fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next;
        } 

        ListNode* deletedNode = slow -> next;
        slow -> next = slow -> next -> next;
        delete deletedNode;

        return head;


    }
};