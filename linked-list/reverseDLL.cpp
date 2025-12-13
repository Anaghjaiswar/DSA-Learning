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

// thiinking process 

// we can maintain a stack as we process the linked list , in a for loop we put it elements in a stack.
// nusing a temp variable , then again temp goes to head , 
// now when it does the second iteration it replaces the data in linked list from stack top values

Node* reverseDLLinSingleIteration(Node* head){
    // we will handle the case if it's a single element list
    if(head == NULL || head -> next == NULL){
        return head;
    }
    
    Node* current = head;
    Node* lastNode = nullptr; // To keep track of the new head

    while(current != NULL){
        lastNode = current; // The last non-null node will be the new head
        Node* back = current -> prev;
        current -> prev = current -> next;
        current -> next = back;

        // go the next node , ideally you should have written current -> next 
        // but you will write current -> prev , because you already swapped the pointers
        current = current -> prev;
    }

    return lastNode;
}

void printList(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    vector<int> arr = {12, 5, 8, 7,6, 8, 9};
    Node* head = convertToDoublyLL(arr);

    cout << "Original doubly linked list is: " << endl;
    printList(head);

    // --- Method 1: Reversing data using a stack (Brute Force) ---
    // This method takes O(N) space for the stack and O(2N) time.
    cout << "\nReversing data using a stack:" << endl;
    if (head) {
        stack<int> s;
        Node* temp = head;
        // we are iterating on the linked list and placing all our element in stack 
        while (temp){
            s.push(temp-> data);
            temp = temp -> next;
        }
        temp = head;  // back to first value

        // in the next iteration we replaced the data with stack top values 
        while(temp){
            temp -> data = s.top();
            s.pop();
            temp = temp-> next;
        }
        cout << "List after reversing data: " << endl;
        printList(head);
    }

    // --- Method 2: Reversing pointers in a single iteration (Optimal) ---
    // This method takes O(1) space and O(N) time.
    // We re-create the list to show the pointer reversal on the original data.
    head = convertToDoublyLL(arr); 
    cout << "\nReversing pointers in a single iteration:" << endl;
    cout << "Original list again: " << endl;
    printList(head);

    head = reverseDLLinSingleIteration(head);
    cout << "List after pointer reversal: " << endl;
    printList(head);

    return 0;
}