#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N; cin >> N;
    while(N--)
    {
        int n; cin >> n;
        int select[n+1] = {0, };
        int visited[n+1] = {0, };
        for(int i = 1; i < n+1; i++) 
        {
            cin >> select[i];
            if(select[i] == i) visited[i] = -1;
        }
    
        
        for(int i = 1; i < n+1; i++) 
        {
            stack<int> S;
            if(!visited[i]) S.push(i);
            bool isTeam = false;
            while (!S.empty())
            {
                int top = S.top(); S.pop();
                if(visited[top] != 0) break;
                visited[top] = i;
                if(select[top] == i)
                {
                    isTeam = true;
                    break;
                }
                S.push(select[top]);
            }
            if(!isTeam)
            {
                for(int k = 1; k < n+1; k++)
                {
                    if(visited[k] == i) visited[k] = 0;
                } 
            }
        }
        int result = 0;
        for(int i = 1; i < n+1; i++)
            if(visited[i] == 0) result++;
        
        cout << result << "\n";
    }
}