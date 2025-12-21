#include<bits/stdc++.h>
using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2)
    {
        val = data1;
        next = next1;
        child = next2;
    }
};

class Solution {
public:
    ListNode* flattenLinkedList(ListNode* &head) {
        // we can perform merge suppose on first 2 child nodes and then continue it forward
        vector<ListNode* > lists;
        ListNode* temp = head;
        while(temp){
            lists.push_back(temp);
            temp = temp -> next;
        }

        // our list is formed , now this question is pretty similiar to merge k sorted lists

        if (lists.empty()) return nullptr;

        int n = lists.size();
        return mergeRange(lists, 0, n - 1);
    }
private:
    ListNode* mergeRange(vector<ListNode*>& lists, int left, int right){
        if (left > right) return nullptr;
        if (left == right) return lists[left];

        int mid = left + (right - left) / 2;
        ListNode* l1 = mergeRange(lists, left, mid);
        ListNode* l2 = mergeRange(lists, mid + 1, right);

        return merge2lists(l1, l2);
    }

    ListNode* merge2lists(ListNode* l1, ListNode* l2){
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode* top = nullptr;
        ListNode* bottom = nullptr;

        if(l1 -> val <= l2 -> val){
            top = l1;
            bottom = l1;
            l1 = l1 -> child;
        }else{
            top = l2;
            bottom = l2;
            l2 = l2 -> child;
        }

        bottom -> next = nullptr;
        
        while(l1 && l2){
            if (l1 -> val <= l2 -> val){
                bottom -> child = l1;
                l1 = l1 -> child;
            } else {
                bottom -> child = l2;
                l2 = l2 -> child;
            }
            bottom = bottom -> child;
            bottom -> next = nullptr;
        }

        if (l1 != nullptr){
            bottom -> child = l1;
        }
        else{
            bottom -> child = l2;
        }
        return top;
    }

};