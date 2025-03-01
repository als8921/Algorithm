#include <bits/stdc++.h>

using namespace std;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int N, M, K;

char graph[1001][1001];
int visited[1001][1001][11];
int main()
{
    fill(&visited[0][0][0], &visited[0][0][0] + 1001 * 1001 * 11, 0);
    cin >> N >> M >> K;

    for(int y = 0; y < N; y++)
        for(int x = 0; x < M; x++)
            cin >> graph[y][x];

    queue<vector<int>> Q;
    Q.push({0, 0, 0});
    visited[0][0][0] = 1;

    int result = 0;

    while(!Q.empty())
    {
        int y = Q.front()[0];
        int x = Q.front()[1];
        int breakCount = Q.front()[2];
        Q.pop();

        if(y == N - 1 && x == M - 1)
        {
            if(result) result = min(result, visited[y][x][breakCount]);
            else result = visited[y][x][breakCount];
        }

        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if((!visited[ny][nx][breakCount] || visited[ny][nx][breakCount] > visited[y][x][breakCount] + 1)  && graph[ny][nx] == '0')
            {
                visited[ny][nx][breakCount] = visited[y][x][breakCount] + 1;
                Q.push({ny, nx, breakCount});
            }
            if(breakCount + 1 <= K && (!visited[ny][nx][breakCount + 1] || visited[ny][nx][breakCount + 1] > visited[y][x][breakCount] + 1) && graph[ny][nx] == '1')
            {
                if(visited[y][x][breakCount] % 2)
                    visited[ny][nx][breakCount + 1] = visited[y][x][breakCount] + 1;
                else 
                    visited[ny][nx][breakCount + 1] = visited[y][x][breakCount] + 2;
                Q.push({ny, nx, breakCount + 1});
            }
        }
    }

    if(result) cout << result << "\n";
    else cout << "-1\n";
}