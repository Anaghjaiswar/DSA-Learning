#include<bits/stdc++.h>
using namespace std;

// what we need to do is add linked list;
// a linked list say
// 6 -> 5 -> 4 -> 3  = this will give me number 3456
// another linked list is 
// 9 -> 8 = = this will give me number 89

// i have to add 89 +  3456 = 3545 
// and return a linked list as 5 -> 4 -> 5 -> 3 == 3545

// we add the unit digits we cary the cary forward , and so on
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

Node* convertToDoublyLL(vector<int> arr){
    int n = arr.size();
    if (n == 0) {
        return nullptr;
    }
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i = 1; i < n; i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev -> next = temp;
        prev = temp;
    }
    return head;
}

void printList(Node* temp){
    while(temp){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

Node* addTwoLinkedList(Node* temp1, Node* temp2){
    Node* CombinedList =  nullptr;
    Node* head = nullptr;
    int carry = 0;

    while(temp1 && temp2){

        int sum = (temp1-> data) + (temp2 -> data) +  carry;
        int val; // to store the digit we want to save
        if (sum > 9){
            val = sum - 10;
            carry = 1;
        }
        else {
            val = sum;
            carry = 0;
        }

        Node* newNode = new Node(val);

        if(head == nullptr){
            // if this is the first node
            head = newNode;
            CombinedList = newNode;
        }
        else{
            // if this is not the first node
            CombinedList -> next = newNode;
            newNode -> prev = CombinedList;
            CombinedList = CombinedList -> next;
        }

        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
    while(temp1){
        int sum = temp1 -> data + carry;
        int val;
        if (sum == 10){
            val = 0;
            carry = 1;
        }
        else {
            val = sum;
            carry = 0;
        }
        Node* newNode = new Node(val);
        CombinedList -> next = newNode;
        newNode -> prev = CombinedList;
        CombinedList= CombinedList -> next;
        temp1 = temp1 -> next;
    }
    while(temp2){
        int sum = temp2 -> data + carry;
        int val;
        if (sum == 10){
            val = 0;
            carry = 1;
        }
        else {
            val = sum;
            carry = 0;
        }

        Node* newNode = new Node(val);
        CombinedList -> next = newNode;
        newNode -> prev = CombinedList;
        CombinedList= CombinedList -> next;
        temp2 = temp2 -> next;
    }

    if(carry == 1){
        Node* newNode = new Node(1);
        CombinedList->next = newNode;
        newNode->prev = CombinedList;
    }
    return head;
}


int main(){
    vector<int> arr1 = {2, 5, 8, 7,6, 8, 9};
    Node* head1 = convertToDoublyLL(arr1);
    vector <int> arr2 = {7,8,9,5};
    Node* head2 = convertToDoublyLL(arr2);

    cout << "first linked list"<< endl;
    printList(head1);
    cout << "second linked list"<< endl;
    printList(head2);

    Node* result = addTwoLinkedList(head1, head2); // result will be at last node
    cout << "result linked list"<< endl;
    printList(result);
}

