#include <bits/stdc++.h>

using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int map[500001] = {0, };
    int visited[500001][2];
    fill(&visited[0][0], &visited[0][0] + 500001 * 2, -1);

    queue<pair<int, int>> q;
    q.push({a, 0});
    visited[a][0] = 0;

    while(!q.empty())
    {
        int x = q.front().first; 
        int nt = q.front().second + 1; 
        q.pop();

        for(int nx : {2 * x, x - 1, x + 1})
        {
            if(nx < 0 || nx > 500000) continue;
            if(visited[nx][nt%2] == -1)
            {
                visited[nx][nt%2] = nt;
                q.push({nx, nt}); 
            }
        }
    }

    int result = -1;

    int count = 0;
    while(b <= 500000)
    {
        if(visited[b][count%2] != -1 && visited[b][count%2] <= count)
        {
            result = count;
            break;
        }
        count++;
        b += count;
    }
    cout << result << "\n";
}