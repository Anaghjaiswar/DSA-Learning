#include <bits/stdc++.h>
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

// here Node * means it is returning pointer to the head
Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]); // i have a multi constructor so i don't need to pass nullpointer
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    { // we write 1 bcz we already took fisrt element
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next; // or you can also say mover=temp
    }
    return head;
}

int lengthOfLL(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int checkIfPresent(Node *head, int val)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == val)
            return 1;
        temp = temp->next;
    }
    return 0;
}

Node* deleteHead(Node* head){
    Node* temp = head;
    head = head -> next;
    delete temp; // or free(temp); in java we don't use this becuase of garbage collector,
    return head;
}

Node* deleteTail(Node* head){
    // what if it is null itself
    if(head == nullptr || head -> next == nullptr){
        delete head;
        return nullptr;
    }
    Node* temp = head;

    // if you are standing at a node just one backwards form the last node, then you may be able to remove the last node
    // suppose if for a 2nd last node if it is let's say temp then temp -> next -> next == nullptr
    // so we have to somehow stop at temp while iterating in linked list
    
    while(temp->next->next != nullptr){
        temp = temp -> next;
    }

    // now since we are the 2nd last node , we can simply delete the last node
    delete temp -> next;
    temp -> next = nullptr;
    return head;
}

Node* deleteAtBetween(Node* head , int pos){
    // what is it is null itself
    if(head == NULL )return head;
    if (pos == 1) {
        Node * temp = head;
        head = head -> next;
        delete temp;
        return head;
    }
    int count = 0;
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL ){
        count++;
        // we need to remember 
        if (count == pos){
            prev -> next = prev -> next -> next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp -> next;
    
    }
    return head;
}

int main()
{
    vector<int> arr = {12000000, 5, 8, 7};
    // Node* y = new Node(arr[0], nullptr);

    Node *head = convertArr2LL(arr);
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    int length = lengthOfLL(head);
    cout << endl
         << length << endl;

    if (checkIfPresent(head, 5))
        cout << "found";
    else
        cout << "not found";

    return 0;
}