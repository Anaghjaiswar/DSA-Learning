#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr || (head -> next == nullptr && head -> child == nullptr)) return head;
        vector<int> arr;
        Node* temp = head;

        while(temp){
            arr.push_back(temp-> val);

            if(temp -> child != nullptr){
                insertinArr(temp -> child, arr);
            }
            
            temp = temp -> next;
        }
        return convertToLL(arr);
    }
private:
    void insertinArr(Node* head, vector<int>& arr){
        Node* temp = head;
        arr.push_back(temp -> val);

        if (temp -> child != nullptr){
            insertinArr(temp -> child, arr);
        }

        if (temp -> next != nullptr){
            insertinArr(temp -> next, arr);
        }
        return;
    }
private:
    Node* convertToLL(vector<int> arr){
        if (arr.empty()) return nullptr;

        Node* head = new Node();
        head -> val = arr[0];
        head -> prev = nullptr;
        head -> child = nullptr;

        Node* mover = head;

        for(int i = 1; i <arr.size(); i++){
            Node* node = new Node();
            node -> val = arr[i];
            node->prev = mover;
            node -> next = nullptr;
            node -> child = nullptr;

            mover -> next = node;
            mover = node;

        }
        return head;

    }
};