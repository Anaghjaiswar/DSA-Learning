#include<bits/stdc++.h>
using namespace std;

// Given an array of integers books where books[i] represents the number of pages in the ith book and an integer students representing the number of students.

int findStudents(vector<int>& books, int mid){
    int studentsCount = 1;
    int pagesSum = 0;
    for(size_t i = 0; i < books.size(); i++){
        if((pagesSum + books[i]) <= mid){
            pagesSum += books[i];
        }
        else{
            studentsCount++;
            pagesSum = books[i];
        }
    }
    return studentsCount;
}


int allocate_books(vector<int> &books, int students) {
    int n = books.size();
    if(students > n) return -1; // not enough books to allocate
    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0);
    int ans = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        int studentsCount = findStudents(books, mid);
        if(studentsCount <= students){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}



int main(){
    vector<int> v = {25, 46, 28, 49, 24};
    int books = 4;
    int result = allocate_books(v, books);
    cout << result;
}