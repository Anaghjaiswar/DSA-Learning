#include<bits/stdc++.h>
using namespace std;


// take two stack s1, and s2 
// first step is whatever in s1 , put in s2


// like on first insertion you will not do anything
// in next insertions you will first put the the data of s1 to s2
// and then put the new inserted element to s1 
// and then finally put s2 data back into s1

class MyQueue {
private:
    stack<int> s1; 
    stack<int> s2; // needed in order to store the elements to get it back
    int currSize;
public:
    MyQueue() {
    }
    
    // this approach takes time O(2N) if there so many push operations avoid it
    void push(int x) {
        // if s1 has something get everything from it push to s2
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }

        // put the original data into s1
        s1.push(x);

        // if the s2 has something get everything from it push to s1 again
        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }

        
    }
    
    int pop() {
        if (s1.size() == 0) return -1;
        int poppedElement = s1.top();
        s1.pop();
        return poppedElement;
        
    }
    
    int peek() {
        if(s1.size() == 0) return -1;
        return s1.top();

        
    }
    
    bool empty() {
        return (s1.size() == 0);
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


// another approach

class MyQueue {
private:
    stack<int> s1; 
    stack<int> s2; // needed in order to store the elements to get it back
public:
    MyQueue() {
    }
    
    void push(int x) {
        s1.push(x);

    }
    
    int pop() {
        if (s1.empty() && s2.empty()) return -1;
        int poppedElement;
        if(s2.size() != 0) {
            poppedElement = s2.top();
            s2.pop();
            return poppedElement;
        }else {
            while (s1.size()){
                s2.push(s1.top());
                s1.pop();
                poppedElement = s2.top();
            }
            s2.pop();
            return poppedElement;
        }
    }
    
    int peek() {
        if (s1.empty() && s2.empty()) return -1;
        if(s2.empty() != 0) return s2.top();
        else{
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top(); 
    }
    
    bool empty() {
        return (s1.size() == 0 && s2.size() == 0);
        
    }
};

