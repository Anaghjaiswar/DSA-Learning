// 



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


class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == nullptr ||head -> next == nullptr) return; 
        // 4 steps we need to do here 
        // using fast and slow pointer you have to first find the middle node,
        // after then cut the linked list , from their
        // reverse the second half
        // merge them using zipper like first node from first list second node form second list
        ListNode* secondHead = getMid(head);

        merge2Lists(head, reverseList(secondHead));
    }
private:
    ListNode* getMid(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;

        while(fast && fast -> next){
            prev = slow;
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        // also cut the linked list here only 
        if(prev) prev -> next = nullptr;
        return slow; // this is the head of the new list 
    }

private:
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr){
            ListNode* newNode = curr -> next; // we need the memory of where to look for next value;
            curr -> next = prev;
            prev = curr;
            curr = newNode;
        }

        return prev;
    }

private:
    void merge2Lists(ListNode* head, ListNode* secondHead){
        // we need to save our head becuase main function in returning void
        ListNode* l1 = head;
        ListNode* l2 = secondHead;
        while(l1 && l2){
            ListNode* nextl1 = l1 -> next;
            ListNode* nextl2 = l2 -> next;

            l1 -> next = l2;

            // it means we are at the end of the first half.
            // we have to stop bcz l2 stays connected to it's old remaining chain 
            if (nextl1 == nullptr) break;
            l2 -> next = nextl1;

            l1 = nextl1;
            l2 = nextl2;
            
        }

    }
};



// 1 8 3 7 

// 2 4 5 6 

// 1 as l1
// 8 as nextl1

// 2 as l2
// 4 as nextl2


// l1 -> next = l2 (1 -> 2)
// l2 -> next = nextl1 (1 -> 2 -> 8)

// l1 is at 1 and l2 still at 1
// we need to move them forward
// l1 = nextl1; l1 will be at 8
// l2 = nextl2; l2 will be at 4


// in next iteration 
// 8 as l1
// 3 as nextl1

// 4 as l2
// 5 as nextl2


// 8 -> 4 and 
// 4 -> 3

// means 1 -> 2 -> 8 -> 4 -> 3 and then so on
