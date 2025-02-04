#include<bits/stdc++.h>
using namespace std;

#define Y first
#define X second

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int Map[51][51] = {0, };
int visited[51][51] = {0, };
int main()
{
    int N; cin >> N;
    while(N--)
    {
        queue<pair<int, int>> Q;
        int result = 0;
        int height, width, num;
        for(int i = 0; i < 51; i++)
            for(int j = 0; j < 51; j++)
            {
                Map[i][j] = 0;
                visited[i][j] = 0;
            }

        cin >> width >> height  >> num;
        while(num--)
        {
            int x, y;
            cin >> x >> y;
            Map[y][x] = 1;
        }



        // cout << "----------------------- MAP --------------------------\n";
        // for(int i = 0; i < height; i++)
        // {
        //     for(int j = 0; j < width; j++)
        //         cout << Map[i][j];
        //     cout << "\n";
        // }

        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                if(Map[i][j] == 1 && !visited[i][j])
                {
                    visited[i][j] = 1;
                    result++;
                    Q.push({i, j});
                    while(!Q.empty())
                    {
                        int y = Q.front().Y;
                        int x = Q.front().X;
                        Q.pop();

                        for(int k = 0; k < 4; k++)
                        {
                            int ny = y + dy[k];
                            int nx = x + dx[k];
                            if(ny < 0 || ny >= height || nx < 0 || nx >= width) continue;
                            if(Map[ny][nx] && !visited[ny][nx])
                            {
                                Q.push({ny, nx});
                                visited[ny][nx] = 1;
                            }
                        }
                    }
                }
            }
        }
        cout << result <<"\n";
    }
}