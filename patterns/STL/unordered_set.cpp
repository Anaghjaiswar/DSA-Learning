#include <bits/stdc++.h>

using namespace std;

int main(){
    unordered_set <int> s;
    // inserting between 1 to 10
    for (int i = 1; i <= 10; i++){
        s.insert(i);
    }

    // printing elements in the unordered_set s
    for(auto it = s.begin(); it!=s.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    int n = 2;
    if (s.find(2) != s.end())
    cout << n << " is present in unordered set" << endl;


    s.erase(s.begin()); // deleting the first element of the set
    for (auto it = s.begin(); it != s.end(); it++){
        cout << *it << endl;
    }

     cout << "The size of the unordered set is: " << s.size() << endl;

     if (s.empty()){
        cout << "set is empty";
     } else{
        cout << "set is not empty"<< endl;
     }
     s.clear();
     cout<< "size after clearing:"<< s.size();
 }