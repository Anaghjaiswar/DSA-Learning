#include <bits/stdc++.h>
using namespace std;

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

void printList(Node *temp)
{
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// brute approach ------------------------------------------------------------------------------------------------------
// our approach can be brute force first , that is we will count the number of zeroes ,ones, twos
// and then we again iterate over the data and overwrite the data
// o(1) - space complexity and O(2N) - time complexity
// Node* sortZeroesOnesTwos(Node* head){
//     int zeroesCount = 0;
//     int onesCount = 0;
//     int twosCount = 0;

//     Node* mover = head;

//     while(mover){
//         if (mover -> data == 0){
//             zeroesCount++;
//         }
//         else if(mover -> data == 1){
//             onesCount++;
//         }
//         else{
//             twosCount++;
//         }
//         mover = mover -> next;
//     }

//     mover = head;
//     Node* moverHead = mover;

//     while(mover){
//         if (zeroesCount > 0){
//             mover -> data = 0;
//             zeroesCount--;

//         }
//         else if(onesCount > 0){
//             mover -> data = 1;
//             onesCount--;

//         }
//         else{
//             mover -> data = 2;
//             twosCount--;
//         }
//         mover = mover -> next;
//     }
//     return moverHead;
// }

// another approach ----------------------------------------------------------------------------------------
// join zero nodes , ones nodes and two nodes as you go , and then zerolast = onehead and onelast = twohead
Node* sortZeroesOnesTwos(Node* head){
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);

    // we need pointers to track the tail of the nodes
    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;

    // we need one temp also to move across the head
    Node* temp = head;
    while(temp){
        if (temp -> data == 0){
            zero -> next = temp;
            zero = zero -> next;
        }
        else if (temp -> data == 1){
            one -> next = temp;
            one = one -> next;
        }
        else{
            two -> next = temp;
            two = two -> next;
        }
        temp = temp -> next;
    }


    one -> next = (twoHead -> next) ? twoHead -> next : nullptr;
    
    zero -> next = (oneHead -> next) ? oneHead -> next : nullptr;

    two -> next = nullptr;

    delete oneHead;
    delete twoHead;
    
    Node* newhead = zeroHead -> next;
    delete zeroHead;
    return newhead;


}


int main()
{
    vector<int> arr = {1,1,1,0,0,1,2,0,1,2,1,0,0,1};
    Node *head = convertArr2LL(arr);
    cout << "orginal list: "<< endl;
    printList(head);

    Node* result = sortZeroesOnesTwos(head);
    cout << "sorted linked list of 0's, 1's, 2's: "<< endl;
    printList(result);
    return 0;
}