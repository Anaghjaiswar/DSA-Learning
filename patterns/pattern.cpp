#include <bits/stdc++.h>
using namespace std;

void print1(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void print2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void print3(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

void print4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
}

void print5(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void print6(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n - i + 1; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

// 0th row - 1 star (4,1,4)
// 1st row - 3 star (3,3,3)
// 2nd row - 5 star (2,5,2)
// 3rd row - 7 star (1,7,1)
// 4th row - 9 star (0,9,0)

//  means (2n+1)th star for nth row

//  eg  n = 5
// n-1 th(4) -- 0 spaces (n-5)
// n-2 th(3) -- 1 space (n-4)
// n-3 th(2) -- 2 space (n-3)
// n-4 th(1) -- 3 space (n-2)
// n-5 th(0) -- 4 space (n-1)

//  (n-1) spaces then (2*i + 1) stars then (n-1) spaces

void print7(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (2 * n - 1); j++)
        {
            if (j < (n - i - 1) || j > (n+i-1))
            {
                cout << " ";
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    // print1(n);
    // print2(n);
    print7(n);
}
