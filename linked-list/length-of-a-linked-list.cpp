#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


int calculateLength(ListNode* head){
    ListNode* fast = head;
    ListNode* slow = head;

    bool found = false;
    while(fast && fast -> next){
        fast = fast -> next-> next;
        slow = slow -> next;

        if(fast == slow){
            found = true;
            break;
        }
    }
    // if no cycles
    if (!found) return 0;

    // cycle is detected now 
    int count = 0;
    // fast and slow are at one place , we can move on of them until it again reaches the other 
    // and calculate count

    // guaranteed can't fail due to null pointer dereference
    while(fast){
        fast = fast -> next;
        count++;
        if(fast == slow ) break;
    }
    return count;
}