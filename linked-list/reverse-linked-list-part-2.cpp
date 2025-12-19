#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head -> next == nullptr || head -> next == nullptr || left == right) return head;
        // we need 4 pointers here 
        // we will cut the part reverse it and add
        // we need pointers of both end nodes of cutted list
        // and we need pointers to track where they are cutten off

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* firstTrack = dummy;
        ListNode* cutFirst = nullptr;
        ListNode* cutSecond = nullptr;
        ListNode* secondTrack = nullptr;


        ListNode* curr = dummy; // to iterate over the list

        // track first pointer
        for (int i = 0; i < right; i++) {
            if (i < left - 1) {
                firstTrack = firstTrack->next;
            }
            curr = curr->next; // at last this will be at cutSecond
        }

        // define the remaining 3 pointers
        cutFirst = firstTrack->next;
        cutSecond = curr;
        secondTrack = curr->next;

        // actually cut
        firstTrack->next = nullptr;
        cutSecond->next = nullptr;

        // reverse and join
        firstTrack->next = reverseList(cutFirst);
        cutFirst->next = secondTrack;

        ListNode* result = dummy->next;
        delete dummy; 
        return result;

    }
private:
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr){
            ListNode* newNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = newNode;
        }

        return prev;
    }
};