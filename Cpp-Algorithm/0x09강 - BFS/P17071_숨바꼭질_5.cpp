#include <bits/stdc++.h>

using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int map[500001] = {0, };
    int visited[500001] = {0, };

    queue<int> q;
    q.push(a);
    visited[a] = 1;

    while(!q.empty())
    {
        int x = q.front(); q.pop();

        for(int nx : {2 * x, x - 1, x + 1})
        {
            if(nx < 0 || nx > 500000) continue;
            if(!visited[nx])
            {
                visited[nx] = visited[x] + 1;
                q.push(nx);
            }
        }
    }

    int result = -1;

    int count = 1;
    while(b <= 500000)
    {
        if(visited[b] == count)
        {
            result = count - 1;
            break;
        }
        else if(visited[b] < count && (visited[b] - count) % 2 == 0)
        {
            result = count - 1;
            break;
        }
        b += count++;
    }
    cout << result << "\n";
}