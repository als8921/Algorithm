#include<bits/stdc++.h>
using namespace std;

#define Y first;
#define X second;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int m, n;
int graph[301][301] = {0, };
int visited[301][301] = {0, };

int Count()
{
    int count = 0;
    queue<pair<int, int>> Q;
    for(int yy = 0; yy < m; yy++)
    {
        for(int xx = 0; xx < n; xx++)
        {
            if(graph[yy][xx] && !visited[yy][xx])
            {
                count++;
                Q.push({yy, xx});
                visited[yy][xx] = 1;

                while(!Q.empty())
                {
                    int y = Q.front().Y;
                    int x = Q.front().X; 
                    Q.pop();

                    for(int i = 0; i < 4; i++)
                    {
                        int ny = y + dy[i];
                        int nx = x + dx[i];
    
                        if(ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
                        if(!visited[ny][nx] && graph[ny][nx] != 0)
                        {
                            Q.push({ny, nx});
                            visited[ny][nx] = 1;
                        }
                    }
                }
            }
        }
    }
    fill(&visited[0][0], &visited[0][0] + 301*301, 0);
    return count;
}

void Melt()
{
    for(int yy = 0; yy < m; yy++)
    {
        for(int xx = 0; xx < n; xx++)
        {
            if(graph[yy][xx])
            {
                visited[yy][xx] = 1;
                for(int i = 0; i < 4; i++)
                {
                    int ny = yy + dy[i];
                    int nx = xx + dx[i];

                    if(ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
                    if(!visited[ny][nx] && graph[ny][nx] == 0)
                    {
                        graph[yy][xx]--;
                        if(graph[yy][xx] == 0) break;
                    }
                }
            }
        }
    }
    fill(&visited[0][0], &visited[0][0] + 301*301, 0);
}

int main()
{
    cin >> m >> n;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    int i = 0;
    while(1)
    {
        int cnt = Count();
        if(cnt == 0)
        {
            cout << "0\n";
            break;
        }
        else if(cnt != 1)
        {
            cout << i <<"\n";
            break;
        } 
        
        Melt();
        i++;
    }
    
}