#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};


class Stack{
    Node* topNode = nullptr;
    int size = 0;

public:
    void push(int x){
        Node* curr = new Node(x);
        curr -> next = topNode;
        topNode = curr;
        size++;
    }

    void pop(){
        if(topNode == nullptr){
            cout << "Stack Underflow";
            return;
        }
        Node* temp = topNode;
        topNode = topNode -> next;
        delete temp;
        size--;
    }

    int top(){
        if(topNode == nullptr) return -1; 
        return topNode -> data;
    }

    int size(){
        return size;
    }
};




