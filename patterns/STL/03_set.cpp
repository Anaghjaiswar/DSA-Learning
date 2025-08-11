#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> s;

    // inserting elements into the set
    for(int i=1;i<=10;i++){
        s.emplace(i);
    }

    // view elements of the set
    for (auto it = s.cbegin(); it!= s.cend(); it++){
        cout << *it<< " "; 
    }

    cout << endl;
    cout << s.count(5) <<" "<< s.count(11)<<endl; // if 5 is in the set it will print 1 otherwise zero

    int n;
    cout << "Enter n:";
    cin >> n;
    if (s.find(n) != s.end()){
        cout << n << "is present in the set"<<endl;
    }else{
        cout<< n << "is not present in the set"<< endl;
    }

    s.erase(s.begin());
  cout << "Elements after deleting the first element: ";
  for (auto it = s.begin(); it != s.end(); it++) {
    cout << * it << " ";
  }
  cout << endl;
  cout << "The size of the set is: " << s.size() << endl;
}