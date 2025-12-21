#include<bits/stdc++.h>
using namespace std;

// 1. Define the Node structure
struct Node {
    string url;
    Node* next;
    Node* prev;

    // Constructor for easier node creation
    Node(string u) : url(u), next(nullptr), prev(nullptr) {}
};
// we have to design a browser history

class BrowserHistory {
    Node* current;

public:
    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }


    void visit(string url){
        Node* newNode = new Node(url);
        
        // MEMORY CLEANUP: 
        // If there is existing forward history, we must delete it to prevent leaks.
        Node* forwardNode = current->next;
        while(forwardNode != nullptr) {
            Node* temp = forwardNode;
            forwardNode = forwardNode->next;
            delete temp;
        }

        // LINKING LOGIC:
        current->next = newNode; // Link old node to new node
        newNode->prev = current; // Link new node back to old node (Crucial Fix)
        current = newNode;       // Move pointer
        
        cout << "Visited: " << current->url << endl;
    }

    string back(int steps) {
        // Move back as long as steps > 0 AND a previous node exists
        while (steps > 0 && current->prev != nullptr) {
            current = current->prev;
            steps--;
        }
        return current->url;
    }

    // 5. Forward Function
    string forward(int steps) {
        // Move forward as long as steps > 0 AND a next node exists
        while (steps > 0 && current->next != nullptr) {
            current = current->next;
            steps--;
        }
        return current->url;
    }
};