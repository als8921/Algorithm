#include<bits/stdc++.h>
using namespace std;

#define Y first;
#define X second;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int main()
{
    int n;
    cin >> n;

    int maxHeight = 0;
    int graph[n][n] = {0, };
    for(int y = 0; y < n; y++)
        for(int x = 0; x < n; x++)
        {
            cin >> graph[y][x];
            maxHeight = max(maxHeight, graph[y][x]);
        }

    int result = 0;
    for(int height = 0; height < maxHeight; height++)
    {
        queue<pair<int, int>> Q;
        int visited[n][n];
        fill(&visited[0][0], &visited[0][0] + n * n, 0);
    
        int count = 0;
        for(int yy = 0; yy < n; yy++)
            for(int xx = 0; xx < n; xx++)
            {
                if(!visited[yy][xx] && graph[yy][xx] > height){
                    visited[yy][xx] = 1;
                    Q.push({yy, xx});
                    count++;
                }
                while(!Q.empty())
                {
                    int y = Q.front().Y;
                    int x = Q.front().X;
                    Q.pop();
    
                    for(int i = 0; i < 4; i++)
                    {
                        int ny = y + dy[i];
                        int nx = x + dx[i];
    
                        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                        if(!visited[ny][nx] && graph[ny][nx] > height)
                        {
                            visited[ny][nx] = 1;
                            Q.push({ny, nx});
                        }
                    }
                }
            }
        result = max(result, count);
    }
    cout << result << "\n";
}