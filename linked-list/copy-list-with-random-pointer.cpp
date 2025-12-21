#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// O(2N) - TC, O(N + N) - SC, an xtra space bcz it is req.
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        unordered_map<Node*, Node*> mpp;

        // create the dummy nodes and store it in hashmap
        while(temp){
            Node* newNode = new Node(temp -> val);
            mpp[temp] = newNode;
            temp = temp -> next;
        }

        temp = head;

        // now since copy nocdes are their ,copy the linking part also form the original one 
        while(temp){
            Node* copyNode = mpp[temp];
            copyNode -> next = mpp[temp -> next];
            copyNode -> random = mpp[temp -> random];
            temp = temp -> next;
        }

        temp = head;
        return mpp[temp]; // return the copied head 
        
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        // nodes in between
        insertCopyNodeInBetween(head);
        connectRandomPointers(head);
        // connect next pointer and return the deep copy of the list
        return getCopiedList(head);
    }
private:
    void insertCopyNodeInBetween(Node* head){
        Node* temp = head;
        while(temp){
            Node* nextElement = temp -> next;
            //i created the copied node
            Node* copyNode = new Node(temp -> val);

            // join them in between
            copyNode -> next = nextElement;
            temp -> next = copyNode;

            // move to the next original node
            temp = nextElement;
        }
    }
private:
    void connectRandomPointers(Node* head){
        Node* temp = head;
        while(temp != nullptr){
            Node* copyNode = temp -> next;

            // if the orginal node has a random pointer
            if(temp -> random != nullptr){

                copyNode -> random = temp -> random -> next;

            }
            else{
                copyNode -> random = nullptr;
            }

            temp = temp -> next -> next;
        }
    }
private:
    Node* getCopiedList(Node* head){
        Node* temp = head;
        Node* dummyNode = new Node(-1);

        Node* curr = dummyNode;

        while(temp != nullptr){
            // creating a new list by pointing to copied nodes
            curr -> next = temp -> next;
            curr = curr -> next;

            // disconnect and revert back to the initial state of the original LL
            temp -> next = temp -> next -> next;
            temp = temp -> next;
        }

        return dummyNode -> next;
    }
};