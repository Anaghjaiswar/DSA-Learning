#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// normal brute implementation
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head -> next == nullptr) return nullptr;
        unordered_set <ListNode* > seen;
        ListNode* temp = head;
        
        while(temp){
            if (!seen.count(temp)){
                seen.insert(temp);
            }
            else {
                // if it is seen
                return temp;
            }
            temp = temp -> next;
        }
        return nullptr;

    }
};



