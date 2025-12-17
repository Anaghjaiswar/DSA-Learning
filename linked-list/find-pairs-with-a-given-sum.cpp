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


// important thing here is input list is a SORTED doubly linked list

vector<vector<int>> findPairsWithGivenSum(Node* head, int target) {
    Node* right = head;
    vector <vector<int>> pairs;

    while(right -> next) right = right -> next;
    // now right is at tail
    
    Node* left = head;

    while(left != right && left -> prev != right){
        int sum = (left -> data) + (right -> data);
        if (sum == target) {
            pairs.push_back({left->data, right->data});
            left = left -> next;
            right = right -> prev;
        }
        else if (sum > target) right = right->prev;
        else left = left->next;
    }
    return pairs;

}

