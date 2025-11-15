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



// we need to insertion
// 3 cases
// inserting at starting , insert at last , insert at some pos.
// we will handle all cases in one single function
Node *insert(Node *head, int val, int pos)
{
    if (head == NULL) {
        if (pos == 1) return new Node(val);
        return head;
    }
    // Case 1: Insertion at the beginning.
    if (pos == 1){
        Node *temp = new Node(val, head);
        return temp;
    }
 
    // Case 2: Insertion at a position other than the beginning.
    Node *temp = head;
    int count = 0;
 
    while (temp -> next != NULL){
        count++;
        if(count == pos - 1){ // temp standing at one position behind where insertion need to be made
            Node* newNode = new Node(val, temp -> next);
            temp -> next = newNode;
            break;
        }
        temp = temp -> next;
    
    }
    return head;
}



int main()
{
    vector<int> arr = {12000000, 5, 8, 7};
    // Node* y = new Node(arr[0], nullptr);

    Node *head = convertArr2LL(arr);


    head = insert(head, 34, 6);

    // The head pointer might change if we insert at the beginning.
    // It's important to update it.
    Node *temp = head;

    cout << "Linked list after insertion: ";
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}