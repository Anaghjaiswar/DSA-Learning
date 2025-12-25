// Min Stack kya hota hai? (One-liner)

// Min Stack ek aisa stack hai jisme tum:
// push
// pop
// top
// getMin() → current stack ka minimum element

// sab O(1) time mein kar sakte ho.

// Normal stack min nikalne ke liye O(n) lagta hai.
#include<bits/stdc++.h>
using namespace std;








class MinStack {
private: 
    stack <int> st; // main stack
    stack <int> minSt; // to story historuy of min values

public:
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if (minSt.size() != 0){
            // becuase top value of minSt will always be minimum
            
            // push the minimum only whatever is minimum
            minSt.push(min(minSt.top(), st.top()));
        }
        else{
            minSt.push(st.top());
        }
    }
    
    void pop() {
        if (st.size() == 0) return; 
        st.pop();
        minSt.pop();
    }
    
    int top() {
        if (st.size() == 0) return -1; 
        return st.top();
        
    }
    
    int getMin() {
        if(minSt.size() == 0) return -1;
        return minSt.top();
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */



//  another approahc jsut use the same thing but in a different data structure
// pair


class MinStack {
private: 
    stack <pair<int,int>> st; 

public:
    MinStack() {
    }
    
    void push(int val) {
        // we need to directly push if it's the first element 
        if(st.size() == 0) st.push({val, val}); 

        // for another elements we push the min only in the second of pair object
        st.push({val, min(st.top().second, val)});
    }
    
    void pop() {
        if (st.size() == 0) return; 
        st.pop();
    }
    
    int top() {
        if (st.size() == 0) return -1; 
        return st.top().first;
        
    }
    
    int getMin() {
        return st.top().second;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */