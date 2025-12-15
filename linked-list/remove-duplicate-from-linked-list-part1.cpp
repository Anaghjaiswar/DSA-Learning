// Given the head of a sorted linked list, delete all duplicates such that each element
// appears only once. Return the linked list sorted as well.

#include <bits/stdc++.h>
using namespace std;



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// brute approach
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* mover = head;
        ListNode* ansHead = mover;

        while(mover){
            int data = mover -> val;
            ListNode* temp = mover;
            while (temp -> next != nullptr && temp -> next -> val == data){
                temp = temp -> next;
            }

            mover -> next = temp -> next;
            mover = mover -> next;    
        }
        return ansHead;
    }
};


// since the list is ascending order we just check the current vale with prev value

ListNode* deleteDuplicateNode(ListNode* head){
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* mover = head;

    while(mover != nullptr && mover -> next != nullptr){


        if (mover -> val == mover -> next -> val){
            ListNode* DuplicateNode = mover -> next;
            mover -> next = mover -> next -> next;
            delete DuplicateNode;
        }
        else{
            mover = mover -> next;
        }
        
    }
    return head;

}


