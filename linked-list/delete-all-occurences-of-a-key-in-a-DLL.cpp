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


Node* deleteAllOccurencesInAKey(Node* head, int key){
    Node* temp = head;

    // if there is nothing simply return nothing :)
    if (head == nullptr) return nullptr;

    // if only head exists and data of head exists then delete that head and return nullptr
    if((head -> next == nullptr) && (head -> data == key)) {
        return nullptr;
    }

    while(temp){
        if (temp -> data == key){
            Node* deletedNode = temp;
            Node* prevNode = temp -> prev;
            Node* nextNode = temp -> next;
            if (prevNode == nullptr) head = nextNode;
            else prevNode -> next = nextNode;
            if (nextNode != nullptr) nextNode->prev = prevNode;    
            delete temp;
            temp = nextNode;
        }
        temp = temp -> next;
    }
    return head;
}