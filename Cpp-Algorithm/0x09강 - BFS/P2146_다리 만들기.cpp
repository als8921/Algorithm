#include<bits/stdc++.h>
using namespace std;

#define Y first;
#define X second;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int n;
int graph[101][101] = {0, };
int visited[101][101] = {0, };

int IndexingIsland()
{
    int count = 0;
    queue<pair<int, int>> Q;
    for(int yy = 0; yy < n; yy++)
    {
        for(int xx = 0; xx < n; xx++)
        {
            if(graph[yy][xx] && !visited[yy][xx])
            {
                count++;
                Q.push({yy, xx});
                visited[yy][xx] = 1;
                graph[yy][xx] = count;

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
                        if(!visited[ny][nx] && graph[ny][nx] != 0)
                        {
                            Q.push({ny, nx});
                            graph[ny][nx] = count;
                            visited[ny][nx] = 1;
                        }
                    }
                }
            }
        }
    }
    fill(&visited[0][0], &visited[0][0] + 101*101, 0);
    return count;
}

bool IsEdge(int y, int x)
{

    for(int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if(graph[ny][nx] == 0) return true;
    }
    return false;
}

int MakeBridge()
{
    int result = 10000;
    for(int yy = 0; yy < n; yy++)
    {
        for(int xx = 0; xx < n; xx++)
        {
            queue<pair<int, int>> Q;
            if(graph[yy][xx]!=0 && IsEdge(yy, xx))
            {
                visited[yy][xx] = 1;
                Q.push({yy, xx});
                
                while(!Q.empty())
                {
                    int y = Q.front().Y;
                    int x = Q.front().X;
                    Q.pop();

                    if(result < visited[y][x]) continue;
                    for(int i = 0; i < 4; i++)
                    {
                        int ny = y + dy[i];
                        int nx = x + dx[i];
    
                        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                        if(graph[ny][nx]!= 0 && graph[ny][nx] != graph[yy][xx])
                        {
                            result = min(result, visited[y][x] - 1);
                            while(!Q.empty()) Q.pop();
                        } 
                        else if(!visited[ny][nx] && graph[ny][nx] == 0)
                        {
                            Q.push({ny, nx});
                            visited[ny][nx] = visited[y][x] + 1;
                        }
                    }
                }
                fill(&visited[0][0], &visited[0][0] + 101*101, 0);
            }
        }
    }
    return result;
}

int main()
{
    cin >> n;

    for(int yy = 0; yy < n; yy++)
        for(int xx = 0; xx < n; xx++)
            cin >> graph[yy][xx];

    IndexingIsland();
    cout << MakeBridge() <<"\n";
}
