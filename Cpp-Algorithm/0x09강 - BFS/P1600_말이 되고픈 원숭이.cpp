#include<bits/stdc++.h>
using namespace std;

int graph[201][201];
int visited[201][201][31];
int k, w, h;

int mongkeyDy[4] = {-1, 1, 0, 0};
int mongkeyDx[4] = {0, 0, -1, 1};

int HorseDy[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int HorseDx[8] = {1, -1, 1, -1, 2, -2, 2, -2};

int main()
{
    cin >> k >> w >> h;
    fill(&graph[0][0], &graph[0][0] + 201 * 201, 0);
    fill(&visited[0][0][0], &visited[0][0][0] + 201 * 201 * 31, 0);

    for(int y = 0; y < h; y++)
    {
        for(int x = 0; x < w; x++)
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
        int horseCnt = Q.front()[2];
        Q.pop();

        if(y == h - 1 && x == w - 1)
        {
            cout << visited[y][x][horseCnt] - 1 << "\n";
            return 0;
        }

        for(int i = 0; i < 8; i++)
        {
            int ny = y + HorseDy[i];
            int nx = x + HorseDx[i];


            if(ny < 0 || ny >= h || nx < 0 || nx >= w || horseCnt + 1 > k) continue;
            if(!visited[ny][nx][horseCnt + 1] && graph[ny][nx] == 0)
            {
                Q.push({ny, nx, horseCnt + 1});
                visited[ny][nx][horseCnt + 1] = visited[y][x][horseCnt] + 1;
            }
        }
        for(int i = 0; i < 4; i++)
        {
            int ny = y + mongkeyDy[i];
            int nx = x + mongkeyDx[i];

            if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if(!visited[ny][nx][horseCnt] && graph[ny][nx]== 0)
            {
                Q.push({ny, nx, horseCnt});
                visited[ny][nx][horseCnt] = visited[y][x][horseCnt] + 1;
            }
        }
    }
    cout << "-1\n";
}