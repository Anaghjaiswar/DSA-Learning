# binary trees

they are heirachial data structures that consist of nodes, where each node has at most two children, referred to as the left child and the right child. The topmost node is called the root, and nodes with no children are called leaves. Binary trees are used in various applications such as expression parsing, searching algorithms, and representing hierarchical data. They can be traversed in different ways, including pre-order, in-order, and post-order traversal.


# ancestors
In a binary tree, an ancestor of a node is any node that is on the path from the root to that node. This includes the parent node, grandparent node, and so on, up to the root. For example, if we have a binary tree with a root node A, and A has a left child B and a right child C, then A is an ancestor of both B and C. If B has a left child D, then A and B are ancestors of D. Ancestors play an important role in various algorithms and operations on binary trees, such as finding the lowest common ancestor of two nodes or determining the depth of a node in the tree.


# types of binary trees
5 types of binary trees:

1. Full Binary Tree
2. Complete Binary Tree
3. Perfect Binary Tree
4. Balanced Binary Tree
5. Degenerate Binary Tree

1. Full Binary Tree: A full binary tree is a binary tree in which every node has either 0 or 2 children. In other words, no node in a full binary tree has only one child. For example, the following tree is a full binary tree:
```
        A
       / \
      B   C
     / \
    D   E
```
2. Complete Binary Tree: A complete binary tree is a binary tree in which every level of the tree is completely filled, except possibly the last level, which is filled from left to right. in other words, all the nodes are as far left as possible. For example, the following tree is a complete binary tree:
```
        A
       / \
      B   C
     / \
    D   E
   /
  F
```

3. Perfect Binary Tree: A perfect binary tree is a binary tree in which every internal node has exactly two children, and all the leaves are at the same level. For example, the following tree is a perfect binary tree:
```
        A
       / \
      B   C
     / \ / \
    D  E F  G
``` 

4. Balanced Binary Tree: A balanced binary tree is a binary tree in which the heights of the left and right subtrees of every node differ by at most one. For example, the following tree is a balanced binary tree:     
```
        A
       / \
      B   C
     / 
    D   
```

5. Degenerate Binary Tree: A degenerate binary tree is a binary tree in which all the leaves are at the same level. For example, the following tree is a degenerate binary tree:
```
        A
         \
          B
           \
            C
             \
              D
               \
                E
                 \
                  F
```

# representation of binary trees
Struct representation of a binary tree node in C:
```c
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

Node(int val) {
    data = val;
    left = NULL;
    right = NULL;
}

main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
}       
```
In this representation, each node of the binary tree contains an integer data field and two pointers, left and right, which point to the left and right child nodes, respectively. The root of the binary tree is typically represented by a pointer to the topmost node.


# traversal of binary trees
Traversal of binary trees refers to the process of visiting each node in a specific order. There are three common types of traversal:
1. Pre-order Traversal: In pre-order traversal, the nodes are visited in the following order: root, left subtree, right subtree(NLR). For example, for the following binary tree:
```
        A
       / \
      B   C
     / \
    D   E
```
C++ code for pre-order traversal:
```c++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void preOrder(Node* node) {
    if (node == NULL)
        return;
    
    cout << node->data << " "; // Visit root
    preOrder(node->left);       // Traverse left subtree
    preOrder(node->right);      // Traverse right subtree
}
```

the pre-order traversal would be: A, B, D, E, C.

2. In-order Traversal: In in-order traversal, the nodes are visited in the following order: left subtree, root, right subtree(LNR). For the same binary tree as above, the in-order traversal would be: D, B, E, A, C.


3. Post-order Traversal: In post-order traversal, the nodes are visited in the following order: left subtree, right subtree, root(LRN). For the same binary tree as above, the post-order traversal would be: D, E, B, C, A.
