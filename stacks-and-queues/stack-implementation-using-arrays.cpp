#include<bits/stdc++.h>
using namespace std;

class Stack{
    int top = -1;
    int st[10];

    void push(int x){
        if(top >= 10) cout << "stack size exceed";
        top = top + 1;
        st[top] = x;
    }

    int top(){
        if (top == -1) cout << "stack is empty";
        return st[top];
    }

    int size(){
        return top + 1;
    }
};