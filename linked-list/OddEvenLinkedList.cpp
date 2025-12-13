// Given the head of a singly linked list, group all the nodes with odd indices together 
// followed by the nodes with even indices, and return the reordered list.

// The first node is considered odd, and the second node is even, and so on.

// Note that the relative order inside both the even and odd groups should remain as it was in the input.

// You must solve the problem in O(1) extra space complexity and O(n) time complexity.

#include<bits/stdc++.h>
using namespace std;



struct Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};


Node *convertArr2LL(vector<int> &arr)
{
    int n = arr.size();
    if (arr.empty())
    {
        return nullptr;
    }
    Node *head = new Node(arr[0]); // i have a multi constructor so i don't need to pass nullpointer
    Node *mover = head;
    for (int i = 1; i < n; i++)
    { // we write 1 bcz we already took fisrt element
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next; // or you can also say mover=temp
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


// first initial apporach , take a list node , simple and take a temp value 
// temp first value go into linked list and then we jump of by 2 places , and values keep adding in linked lsit,
// after that we shift temp = head -> next and then then we again do the ineratiion jumping 2 places , 
// so ideally o(n/2) + o(n/2) = o(n)

// Node* seggregateOddAndEvenNodes(Node* head){
//     if (head == nullptr) return nullptr;

//     Node* newhead = nullptr;
//     Node* tail = nullptr;
//     Node* temp = head;
//     int count = 2;

//     while(count > 0){

//         // we need to repeat this process 2 times firstly to capture n/2 odd nodes then n/2 even nodes
//         while(temp){
//             Node* newNode = new Node(temp -> data);
//             if(newhead == nullptr){
//                 // first time insertion
//                 tail = newNode;
//                 newhead = newNode;
//             }
//             else{
//                 tail -> next = newNode;
//                 tail = tail -> next;
//             }
            
//             if(temp->next != nullptr){
//                 temp = temp->next->next;
//             } else {
//                 temp = nullptr; // Stop if we can't jump 2 steps
//             }
//         }
//         count--; 
//         temp = head -> next;
//     }
//     return newhead;
// }


// another better approach is take first node as odd and second node(head->next = even)
// use the same way above , connect all the odd nodes and then collect all the even nodes, odd node -> last = even node ki start

Node* seggregateOddAndEvenNodes(Node* head){
    if (head == nullptr) return nullptr;

    Node* odd = head;
    Node* even = head -> next;
    Node* evenHead = even; // this is needed becase we need to conenct odd nodes with even at last
    Node* oddHead = odd;

    // zipper type (we check fo reven because it is ahead)
    while(even != nullptr &&  even -> next !=  nullptr){

        // capture odd nodes first
        odd -> next = even -> next;
        odd = odd -> next;

        // capture even modes second
        even -> next = odd -> next;
        even = even -> next;
    }
    // we do the last linking linking odd nodes to even head 

    odd -> next = evenHead;
    return oddHead;

}


int main(){

    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};

    Node *head = convertArr2LL(arr);
    cout << "original list: "<< endl;
    printList(head); 

    Node* result = seggregateOddAndEvenNodes(head);
    cout << "modified List:" << endl;
    printList(result);

    return 0;
}