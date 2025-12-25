#include<bits/stdc++.h>
using namespace std;



class MyStack {
private:
    queue <int> q;
    int currSize;
public:
    MyStack() {
        currSize = 0;
    }

    void push(int x) {
        q.push(x);
        currSize++;

        for(int i = 0; i < currSize-1; i++){
            q.push(q.front());
            q.pop();
        }
        
    }
    
    int pop() {
        if(q.empty()) return -1;
        int poppedElement = q.front();
        q.pop();
        currSize--;
        return poppedElement;
    }
    
    int top(){
        if(q.empty()) return -1;
        return q.front();
    }
    
    bool empty() {
        return (currSize == 0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */