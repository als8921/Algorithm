#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> Q;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        Q.push(i);

    while(!Q.empty())
    {
        if(Q.size() == 1) 
        {
            cout << Q.front() << "\n";
            return 0;
        }
        Q.pop();
        if(Q.size() == 1) 
        {
            cout << Q.front() << "\n";
            return 0;
        }
        Q.push(Q.front());
        Q.pop();
    }
}