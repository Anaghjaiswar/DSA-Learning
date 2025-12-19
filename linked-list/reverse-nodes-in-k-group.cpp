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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        ListNode* prevNode = nullptr; // tail of previous group
        ListNode* newHead = head;     // final head

        while (temp) {
            ListNode* KthNode = findKthNode(temp, k);

            if (KthNode == nullptr) {
                if (prevNode)
                    prevNode->next = temp;
                break;
            }

            ListNode* nextNode = KthNode->next;
            KthNode->next = nullptr;

            ListNode* reversedHead = reversePartOfLL(temp);

            // first group
            if (temp == head) {
                newHead = reversedHead;
            } else {
                prevNode->next = reversedHead;
            }

            prevNode = temp; // temp becomes tail after reverse
            temp = nextNode;
        }

        return newHead;
    }

private:
    ListNode* reversePartOfLL(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* newNode = curr->next; // we need the memory of where to
                                            // look for next value;
            curr->next = prev;
            prev = curr;
            curr = newNode;
        }

        return prev;
    }

    ListNode* findKthNode(ListNode* head, int k) {
        ListNode* temp = head;
        for (int i = 1; i < k; i++) {
            if (!temp)
                return nullptr;
            temp = temp->next;
        }
        return temp;
    }
};