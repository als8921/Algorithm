#include<bits/stdc++.h>
using namespace std;

int selected[100001];
int visited[100001];
int done[100001];
int cnt = 0;

void dfs(int node)
{
    visited[node] = 1;

    int next = selected[node];

    if(!visited[next]) dfs(next);

    if(!done[next])
    {
        for(int i = next; i != node; i = selected[i]) cnt++;
        cnt++;
    }
    done[node] = 1;
}

int main()
{
    int N; cin >> N;
    while(N--)
    {
        int n; cin >> n;
        cnt = 0;
        fill(selected, selected + 100001, 0);
        fill(visited, visited + 100001, 0);
        fill(done, done + 100001, 0);

        for(int i = 1; i < n+1; i++) 
            cin >> selected[i];
        
        for(int i = 1; i < n+1; i++) 
        {
            if(!visited[i]) dfs(i);
        }
        cout << n - cnt << "\n";
    }
}