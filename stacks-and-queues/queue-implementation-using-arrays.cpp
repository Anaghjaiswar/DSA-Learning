#include<bits/stdc++.h>
using namespace std;

class Queue{
    int start = -1;
    static const int maxSize = 10;
    int Q[maxSize];
    int currSize = 0;
    int end = -1;

public:
    void push(int x){
        if(currSize == maxSize){
            cout << "queue is full";
            return;
        }
        if(currSize == 0){
            start = 0; 
            end = 0;
        }
        else {
            end = (end + 1) % maxSize;
        }

        Q[end] = x;
        currSize += 1;

    }

    int top(){
        if (currSize == 0) cout << "Queue is Empty";
        return Q[start];
    }

    void pop(){
        if (currSize == 0) return;
        int el = Q[start];
        if(currSize == 1){
            start = -1;
            end = -1;
        }
        else {
            start = (start + 1) % maxSize;
        }
        currSize -= 1;
    }
    int size(){
        return currSize;
    }

};