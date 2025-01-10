#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v(201, 0);
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v[temp + 100]++;
    }
    cin >> x;
    cout << v[x + 100];
}