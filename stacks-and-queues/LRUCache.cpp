#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    // Khud ka Node structure
    struct Node {
        int key, val;
        Node *next, *prev;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    // Dummy nodes taaki NULL check ka jhanjhat na rahe
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> m;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // Helper 1: Node ko Head ke just baad add karna (Most Recent)
    void addNode(Node* newnode) {
        Node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    // Helper 2: Pointers change karke node ko beech se nikaalna
    void deleteNode(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            Node* resnode = m[key];
            int res = resnode->val;
            
            // "Most Recent" banane ke liye: Delete karo + Head pe add karo
            m.erase(key);
            deleteNode(resnode);
            addNode(resnode);
            
            m[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        // Agar pehle se hai, to purana wala delete kardo
        if (m.find(key) != m.end()) {
            Node* existingnode = m[key];
            m.erase(key);
            deleteNode(existingnode);
        }

        // Agar cache full hai, to Tail se pehle wala (Least Recent) udao
        if (m.size() == cap) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        // Naya node banao aur Head pe daal do
        addNode(new Node(key, value));
        m[key] = head->next;
    }
};