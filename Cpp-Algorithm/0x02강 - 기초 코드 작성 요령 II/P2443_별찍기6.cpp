#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {   
        for (int j = 0; j < i; j++) cout << " ";
        for (int j = 2 * (n - i - 1) + 1; j > 0; j--) cout << "*";
        cout << "\n";
    }
}