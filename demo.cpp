#include <bits/stdc++.h>
using namespace std;

int equalizeArray(vector<int> arr)
{
    int n = arr.size();
    int el = arr[0];
    int counter = 1;
    for (int i = 1; i < n; i++)
    {
        if (el == arr[i])
        {
            counter++;
        }
        else
        {
            counter--;
            if (counter == 0)
            {
                el = arr[i];
                counter = 1;
            }
        }
    }
    cout << counter;
    int count = 0;
    for (int a : arr)
    {
        if (a == el)
        {
            count++;
        }
    }
    cout << count;

    return n - count;
}

int main()
{
    cout << "Hello, world!" << endl;
    vector <int> v1 = {}
    equalizeArray()
    return 0;
}