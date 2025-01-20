#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    queue<int> Q;
    while(n--)
    {
        string cmd;
        cin >> cmd;
        if(cmd == "push")
        {
            int x;
            cin >> x;
            Q.push(x);
        }
        else if(cmd == "pop")
        {
            if(Q.empty()) cout << "-1\n";
            else
            {
                cout << Q.front() << "\n";
                Q.pop();
            }
        }
        else if(cmd == "size")
        {
            cout << Q.size() << "\n";
        }
        else if(cmd == "empty")
        {
            if(Q.empty()) cout << "1\n";
            else cout << "0\n";
        }
        else if(cmd == "front")
        {
            if(Q.empty()) cout << "-1\n";
            else cout << Q.front() << "\n";
        }
        else if(cmd == "back")
        {
            if(Q.empty()) cout << "-1\n";
            else cout << Q.back() << "\n";
        }
    }
}