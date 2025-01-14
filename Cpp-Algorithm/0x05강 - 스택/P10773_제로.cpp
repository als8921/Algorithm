#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    stack<int> s;
    while(n--)
    {
        int num;
        cin >> num;

        if(num == 0 && !s.empty()) s.pop();
        else s.push(num);
    }

    int sum = 0;
    while(!s.empty())
    {
        sum += s.top();
        s.pop();
    }
    cout << sum;
}