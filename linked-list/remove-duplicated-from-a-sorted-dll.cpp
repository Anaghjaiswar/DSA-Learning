#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data1, Node* next1, Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};


Node* removeDuplicates(Node *head) {
    Node* temp = head;
    
    unordered_set<int> seen;

    while(temp){
        if (!seen.count(temp -> data)){
            seen.insert(temp -> data);
            temp = temp->next;
        }else {
            // now delete the node. 
            Node* prevNode = temp -> prev;
            Node* nextNode = temp -> next;

            if (prevNode == nullptr) head = nextNode;
            else prevNode -> next = nextNode;


            if (nextNode != nullptr) nextNode->prev = prevNode;    
            delete temp;
            temp = nextNode;
            
        }
    }

    return head;


}