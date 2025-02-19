#include<bits/stdc++.h>
using namespace std;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int main(){

    int N, M;
    cin >> N >> M;

    char graph[N][M];
    int visited[N][M][2];
    fill(&visited[0][0][0], &visited[0][0][0] + N * M * 2, 0);

    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < M; x++)
        {
            cin >> graph[y][x];
        }
    }

    
    queue<vector<int>> Q;
    Q.push({0, 0, 0});
    visited[0][0][0] = 1;

    while(!Q.empty())
    {
        int y = Q.front()[0];
        int x = Q.front()[1];
        int wall = Q.front()[2];
        Q.pop();


        if(y ==  N - 1 && x == M - 1)
        {
            cout << visited[y][x][wall] <<"\n";
            return 0;
        }

        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
        
            if(!visited[ny][nx][wall] && graph[ny][nx] == '0')
            {
                Q.push({ny, nx, wall});
                visited[ny][nx][wall] = visited[y][x][wall] + 1;
            }
            if(graph[ny][nx] == '1' && wall == 0)
            {
                Q.push({ny, nx, wall + 1});
                visited[ny][nx][wall + 1] = visited[y][x][wall] + 1;
            }
        }
    }
    cout << "-1\n";
}