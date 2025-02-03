#include<bits/stdc++.h>
using namespace std;

int m[501][501] = {0, };
int visited[501][501] = {0, };

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int height, length;

int maxSize = 0;
int Count = 0;
int tempSize = 0;

void bfs(int y, int x)
{
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= length || ny < 0 || ny >= height) continue;
        if(visited[ny][nx]) continue;

        if(m[ny][nx] == 1)
        {
            visited[ny][nx] = 1;
            tempSize++;
            bfs(ny, nx);
        }
    }
}

int main()
{
    cin >> height >> length;
    for(int y = 0; y < height; y++)
        for(int x = 0; x < length; x++)
            cin >> m[y][x];

    

    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < length; x++)
        {
            if(m[y][x] == 1 && !visited[y][x])
            {
                Count++;
                tempSize++;
                visited[y][x] = 1;
                bfs(y, x);
                maxSize = max(maxSize, tempSize);
                tempSize = 0;
            }
        }
    }
    cout << Count << "\n" << maxSize << "\n";
}

