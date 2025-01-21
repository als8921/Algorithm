#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m;


    deque<int> dq;

    for(int i = 1; i <= n; i++)
        dq.push_back(i);
    int ans = 0;
    while(m--)
    {
        cin >> k;
        int idx;
        for(int i = 0; i < dq.size(); i++)
        {
            if(dq[i] == k)
            {
                idx = i;
                break;
            }
        }


        if(idx <= (int)dq.size() / 2)
        {
            while(dq.front() != k)
            {
                dq.push_back(dq.front());
                dq.pop_front();
                ans++;
            }
            dq.pop_front();
        }
        else
        {
            while(dq.front() != k)
            {
                dq.push_front(dq.back());
                dq.pop_back();
                ans++;
            }
            dq.pop_front();
        }
    }
    cout << ans << "\n";
}