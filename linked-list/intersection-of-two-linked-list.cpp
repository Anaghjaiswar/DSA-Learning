#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



// poor approach O(n*m)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while(temp1){
            while(temp2){
                // cout << "temp1 - data :"<< temp1 -> val << " temp2 - data: " << temp2 -> val<< endl;
                if (temp1 == temp2) return temp1;
                temp2 = temp2 -> next;

            }
            temp2 = headB;
            temp1 = temp1 -> next;
        }
        return nullptr;
    
    }
};



// a better approach using set  TC - O(n+m) ; SC - O(n)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> seen;

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        
        while(temp1){
            seen.insert(temp1);
            temp1 = temp1 -> next;
        }

        while(temp2){
            // Does the exact same node (memory address) exist in the set?”
            if(seen.count(temp2)) return temp2;
            temp2 = temp2 -> next;
        }
        return nullptr;
    
    }
};

// best apporach 
// tc = O(n+m)
// sc = o(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1 = headA;
        ListNode* t2 = headB;

        int l1 = 0;
        int l2 = 0;

        while(t1){
            l1++;
            t1 = t1->next;
        }
        while(t2){
            l2++;
            t2 = t2->next;
        }
        t1 = headA;
        t2 = headB;

        int diff = 0;
        if (l1 > l2){
            diff = l1 - l2;
            while(diff--) {
                t1 = t1 -> next;
            }
        }
        else if ( l1 < l2){
            diff = l2 - l1;
            while(diff--){
                t2 = t2 -> next;
            }
        }

        // now they both are at same level , now you can simply compare

        while(t1){
            if ( t1 == t2) return t1;
            t1 = t1 -> next;
            t2 = t2 -> next;
        }
        return nullptr;


    }
};


// insane solution

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode* a = headA;
        ListNode* b = headB;

        while (a != b) {
            if (a == nullptr)a = headB;
            else a = a->next;

            if (b == nullptr) b = headA;
            else b = b->next;
        }
        return a;
    }
};
