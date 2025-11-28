#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
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
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i = 1; i < n; i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev -> next = temp;
        prev = temp;
    }
    return head;
}


Node* insertNode(Node* head, int pos, int value){

    if (head == NULL){
        if (pos == 1) return new Node(value);
        return head;
    }

    // case 1: insertion at beginning
    if (pos ==1){
        Node* temp = new Node(value, head, nullptr);
        head -> prev = temp;
        return temp;

    }
    
    // case 2: insert at postion other begining

    Node *temp = head;
    int count = 1;

    while(temp-> next != NULL){
        if (count == pos -1){ // temp standing at one position behind where insertion need to be made
            Node* newNode = new Node(value, temp -> next, temp);
            temp -> next -> prev = newNode;
            temp-> next = newNode;
            return head; // Insertion is done, exit the function
        }
        count++;
        temp = temp -> next;
    }

    // Explicitly handle insertion at the last position
    if (count == pos - 1) {
        Node* newNode = new Node(value, nullptr, temp);
        temp->next = newNode;
    }

    return head;
}


Node* deleteNode(Node* head, int pos){
    if (head == NULL || head -> next == nullptr){
        delete head;
        return nullptr;
    }

    // case 1: deleting at start
    if (pos == 1){
        Node* temp = head;
        temp = temp -> next;
        delete head;
        temp -> prev = nullptr;
        return temp;
    }

    // case 2: deletion at between in a certian position
    Node* temp = head;
    int count = 1;
    while(temp -> next != NULL){
        if(count == pos - 1){ // you will be at the one node behind the actual one which needs to be deleted
            Node* temp1 = temp -> next; // node which it to be deleted

            // This check prevents a crash when deleting the last node.
            // If temp1 is not the last node, update the pointers.
            if (temp1->next != nullptr) {
                temp1->next->prev = temp;
            }
            temp->next = temp1->next;

            delete temp1;
            return head; // Return after deletion to avoid case 3 executing.
        } 
        count++;
        temp = temp -> next;
    }

    // case 3: if deletion needed at last
    // This now correctly checks if the intended position is the last node.
    if (count == pos){ 
        temp->prev->next = nullptr; // The second-to-last node's next becomes null.
        delete temp; // Delete the last node.
    }
    return head;
}


int main (){
    vector<int> arr = {12, 5, 8, 7,6, 8, 9};

    Node* head = convertToDoublyLL(arr);

    Node* temp = head;
    while(temp){
        cout << temp -> data << " ";
        temp = temp-> next;
    }
    cout << endl;

    int pos;
    cin >> pos; 


    Node* temp1 = insertNode(head, pos, 5);
    while(temp1){
        cout << temp1 -> data << " ";
        temp1 = temp1-> next;
        
    }

    int position;
    cin >> position;
    Node* temp2 = deleteNode(head, position);
    while(temp2){
        cout << temp2 -> data << " ";
        temp2 = temp2 -> next;

    }

    return 0;


}
