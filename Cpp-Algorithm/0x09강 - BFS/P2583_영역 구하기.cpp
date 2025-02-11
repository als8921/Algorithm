#include<bits/stdc++.h>
using namespace std;

#define Y first
#define X second

int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

int main()
{
    int h, w, n;
    cin >> h >> w >> n;

    int Map[h][w];
    int visited[h][w];

    fill(&Map[0][0], &Map[0][0] + h * w, 0);
    fill(&visited[0][0], &visited[0][0] + h * w, 0);

    while(n--)
    {
        int ys, xs, ye, xe;
        cin >> xs >> ys >> xe >> ye;

        for(int y = ys; y < ye; y++)
        {
            for(int x = xs; x < xe; x++)
            {
                Map[y][x] = 1;
            }
        }
    }


    // for(int y = 0; y < h; y++)
    // {
    //     for(int x = 0; x < w; x++)
    //     {
    //         cout << Map[y][x] << " ";
    //     }
    //     cout << "\n";
    // }
    queue<pair<int, int>> Q;
    vector<int> count;
    for(int yy = 0; yy < h; yy++)
    {
        for(int xx = 0; xx < w; xx++)
        {
            if(!visited[yy][xx] && Map[yy][xx] == 0)
            {
                int cnt = 0;
                visited[yy][xx] = 1;
                Q.push({yy, xx});
                while(!Q.empty())
                {
                    cnt++;
                    int y = Q.front().Y;
                    int x = Q.front().X;
                    Q.pop();

                    for(int i = 0; i < 4; i++)
                    {
                        int ny = y + dy[i];
                        int nx = x + dx[i];

                        if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
                        if(!visited[ny][nx] && Map[ny][nx] == 0)
                        {
                            visited[ny][nx] = 1;
                            Q.push({ny, nx});
                        }
                    }
                }
                count.push_back(cnt);
            }
        }
    }
    sort(count.begin(), count.end());
    cout << count.size() << "\n";
    for(int i : count)
        cout << i << " ";
    cout << "\n";
}