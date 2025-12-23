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
// 1,2,3,4,5

class Queue{
    int size = 0;
    Node* start = nullptr;
    Node* end = nullptr;

    void push(int x){
        Node* newNode = new Node(x);
        if (start = nullptr ){
            start = end = newNode;

        } 
        else{
            end -> next = newNode;
        }
        size++;
    }

    void pop(){
        if (start == nullptr) cout << "Queue is Empty";
        Node* temp = start;
        start = start -> next;
        delete temp;
        size--;
    }

    int top(){
        if (start == nullptr) cout << "Queue is Empty";
        return start -> data;
    }

    int size(){
        return size;
    }
};