#include<iostream>
#include<stack>

using namespace std;
int main()
{
    int n;
    int result = 0;
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;
        stack<char> stk;
        for(char c : s)
        {
            if(c == 'A')
            {
                if(!stk.empty() && stk.top() == 'A') stk.pop();
                else stk.push(c);
            }
            else if(c == 'B')
            {
                if(!stk.empty() && stk.top() == 'B') stk.pop();
                else stk.push(c);
            }
        }
        if(stk.empty()) result++;
    }
    cout << result << "\n";
}