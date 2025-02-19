#include<bits/stdc++.h>
using namespace std;

int dz[] = {0, 0, 0, 0, -1, 1};
int dy[] = {0, 0, -1, 1, 0, 0};
int dx[] = {-1, 1, 0, 0, 0, 0};

void Escape(int L, int R, int C)
{
    char graph[L][R][C];
    int visited[L][R][C];
    fill(&visited[0][0][0], &visited[0][0][0] + L * R * C, 0);

    queue<vector<int>> Q;
    for(int z = 0; z < L; z++)
    {
        for(int y = 0; y < R; y++)
        {
            for(int x = 0; x < C; x++)
            {
                cin >> graph[z][y][x];
                if(graph[z][y][x] == 'S')
                {
                    visited[z][y][x] = 1;
                    Q.push({z, y, x});
                }
            }
        }
    }

    while(!Q.empty())
    {
        int z = Q.front()[0];
        int y = Q.front()[1];
        int x = Q.front()[2];
        Q.pop();

        for(int i = 0; i < 6; i++)
        {
            int nz = z + dz[i];
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(nz < 0 || nz >= L || ny < 0 || ny >= R || nx < 0 || nx >= C) continue;

            if(graph[nz][ny][nx] == 'E')
            {
                cout << "Escaped in " << visited[z][y][x] <<" minute(s).\n";
                return;
            }
            if(!visited[nz][ny][nx] && graph[nz][ny][nx] == '.')
            {
                visited[nz][ny][nx] = visited[z][y][x] + 1;
                Q.push({nz, ny, nx});
            }
        }
    }
    cout << "Trapped!\n";
}

int main()
{
    while(true)
    {
        int L, R, C;
        cin >> L >> R >> C;
    
        if(L == 0 && R == 0 && C == 0) return 0;
        else Escape(L, R, C);
    }
}