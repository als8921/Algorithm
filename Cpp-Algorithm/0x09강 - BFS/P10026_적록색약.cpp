#include<bits/stdc++.h>
using namespace std;

#define Y first
#define X second

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};


int main()
{
    string Map[101];
    int visited[101][101] = {0, };
    int n; cin >> n;

    for(int i = 0; i < n; i++)
    {
        string s; cin >> s;
        Map[i] = s;
    }

    queue<pair<int, int>> Q1;
    queue<pair<int, int>> Q2;

    int result1 = 0;
    int result2 = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            char currentRGB = Map[i][j];
            if(!visited[i][j])
            {
                result1++;
                visited[i][j] = 1;
                Q1.push({i, j});
                while(!Q1.empty())
                {
                    int y = Q1.front().Y;
                    int x = Q1.front().X;
                    Q1.pop();

                    for(int k = 0; k < 4; k++)
                    {
                        int ny = y + dy[k];
                        int nx = x + dx[k];

                        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                        if(!visited[ny][nx] && Map[ny][nx] == currentRGB)
                        {
                            visited[ny][nx] = 1;
                            Q1.push({ny, nx});
                        }
                    }
                }
            }
        }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            visited[i][j] = {0, };

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(Map[i][j] == 'G') Map[i][j] = 'R';

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            char currentRGB = Map[i][j];
            if(!visited[i][j])
            {
                result2++;
                visited[i][j] = 1;
                Q1.push({i, j});
                while(!Q1.empty())
                {
                    int y = Q1.front().Y;
                    int x = Q1.front().X;
                    Q1.pop();

                    for(int k = 0; k < 4; k++)
                    {
                        int ny = y + dy[k];
                        int nx = x + dx[k];

                        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                        if(!visited[ny][nx] && Map[ny][nx] == currentRGB)
                        {
                            visited[ny][nx] = 1;
                            Q1.push({ny, nx});
                        }
                    }
                }
            }
        }

    cout << result1 << " " << result2 << "\n";
}