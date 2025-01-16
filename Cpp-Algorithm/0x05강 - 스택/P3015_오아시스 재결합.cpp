#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long ans = 0;
    cin >> n;


    stack<int> s;
    while(n--)
    {
        int h;
        cin >> h;
        if(!s.empty() && s.top() > h) ans++;
        else if(!s.empty() && s.top() == h) 
        {
            stack<int> temp;
            while(!s.empty() && s.top() >= h)
            {
                temp.push(s.top());
                s.pop();
                ans++;
            }
            while(!temp.empty())
            {
                s.push(temp.top());
                temp.pop();
            }
        }
        else if(!s.empty() && s.top() < h) 
        {
            int lastH = 0;
            stack<int> temp;

            while(!s.empty() && h >= lastH)
            {
                temp.push(s.top());
                lastH = s.top();
                s.pop();
                ans++;
            }
            while(!temp.empty())
            {
                if(temp.top() >= h)
                    s.push(temp.top());
                temp.pop();
            }
        }
        s.push(h);
    }
    cout << ans;
}
/*
7
2 4 1 2 2 5 1
---
10

1. 이전이 현재 보다 높으면 ans++ -> 현재 높이 stack에 추가
2. 이전과 현재가 같으면 ans++ -> 이전 높이 제거 후 현재 높이 stack에 추가
3. 이전이 현재보다 작으면
    ans++
    이전 값 pop
    top이 pop한 값보다 크다면 ans++
    <현재 값보다 작은 값을 모두 제거>
*/