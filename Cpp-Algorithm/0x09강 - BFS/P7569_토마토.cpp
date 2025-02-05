#include<bits/stdc++.h>
using namespace std;

int main()
{
    int dx[] = {-1, 1, 0, 0, 0, 0};
    int dy[] = {0, 0, -1, 1, 0, 0};
    int dz[] = {0, 0, 0, 0 ,-1, 1};


    int m, n, h;
    cin >> m >> n >> h;
    int graph[h][n][m];
    int visited[h][n][m];
    queue<vector<int>> Q;

    for(int k = 0; k < h; k++)
        for(int j = 0; j < n; j++)
            for(int i = 0; i < m; i++)
            {
                cin >> graph[k][j][i];
                visited[k][j][i] = 0;
                if(graph[k][j][i] == 1) 
                {
                    visited[k][j][i] = 1;
                    Q.push({i, j, k});
                }
            }

    while(!Q.empty())
    {
        int x, y, z;
        x = Q.front()[0];
        y = Q.front()[1];
        z = Q.front()[2];
        Q.pop();
        int current = graph[z][y][x];

        for(int i = 0; i < 6; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if(nz < 0 || nz >= h || ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(!visited[nz][ny][nx] && graph[nz][ny][nx] == 0) 
            {
                visited[nz][ny][nx] = 1;
                graph[nz][ny][nx] = current + 1;

                Q.push({nx, ny, nz});
            }
        }
    }

    int result = -1;
    for (int z = 0; z < h; z++)
    {
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                if(graph[z][y][x] == 0)
                {
                    cout << "-1\n";
                    return 0;
                }
                else result = max(result, graph[z][y][x]);

            }
        }
    }
    cout << result-1 << "\n";
}