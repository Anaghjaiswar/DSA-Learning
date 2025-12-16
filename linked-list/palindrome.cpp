#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// O(2N) - time , and O(n) -> space - pure brute implementation
// bool palindromeCheck(ListNode* head){
//     // we need the last node of the list

//     ListNode* temp = head;
//     stack <int> s;

//     while(temp){
//         s.push(temp -> val);
//         temp = temp -> next;
//     }

//     temp = head;

//     while(temp){
//         if (temp -> val == s.top()){
//             s.pop();
//             temp = temp -> next;
//             continue;
//         }
//         else {
//             return false;
//         }
//     }
//     return true;
// }



// any other way 

// like say a palindrome can be 

// a = 1,4,3,5,3,4,1
// b = 1,3,3,1

bool PalindromCheck(ListNode* head){
    if (head == nullptr || head -> next == nullptr) return true;
    
    // we have to first reach the middle node 
    // also we will reach the first middle in case of eeven length linked list
    ListNode* fast = head;
    ListNode* slow = head;

    while((fast -> next != nullptr) && (fast -> next -> next != nullptr)){
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    // now you reverse the second half
    ListNode* secondhead = reverseSecondHalf(slow -> next);
    ListNode* tempNode = secondhead;

    // now we will compare 
    ListNode* firsthead = head;

    while(secondhead != nullptr){
        if (firsthead -> val == secondhead -> val){
            firsthead = firsthead -> next;
            secondhead = secondhead -> next;
        }
        else return false;
    }

    // before returning let's first make the original list as it is
    ListNode* temp2Node = reverseSecondHalf(tempNode);
    slow -> next = temp2Node;
    
    return true;
}


ListNode* reverseSecondHalf(ListNode* head){
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



