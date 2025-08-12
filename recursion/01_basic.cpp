#include<bits/stdc++.h>
using namespace std;

void print_names_n_times(int n, string name, int count = 0){
    if (n==count){
        return;
    }
    cout << name<<endl;
    print_names_n_times(n,name,count+1);

}


int main(){
    int n;
    string name;
    cout << "Enter name: ";
    cin >> name;
    cout<< "Enter number of times: ";
    cin>> n;

    print_names_n_times(n, name);
}