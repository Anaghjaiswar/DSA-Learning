#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> v;

    // pushing elements in vector
    for (int i=1;i<=10;i++){
        v.push_back(i);
    }

    // printing elements in stack
    for (auto it = v.begin(); it!= v.end(); it++){
        cout << *it<< endl;
    }
    cout << "front element: "<< v.front()<<endl;
    cout << "back element: "<< v.back()<<endl;
    cout << "size of vector: "<< v.size()<<endl;

    cout << "###performing operation-1  --> going to delete the "<< v[v.size() - 1]<< "th element from the vector"<<endl;
    v.pop_back() ;

     cout << "\nPrinting the vector after removing the last element:" << endl;
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";


    // inserting 5 at the beginning
    v.insert(v.begin(), 5);
    cout << endl;
    for (int i = 0; i < v.size(); i++){
        cout << v[i]<< ' ';
    }
    // clearing the vector
    v.clear();

    cout << endl<< "size of vector after clearing: "<< v.size();

}
