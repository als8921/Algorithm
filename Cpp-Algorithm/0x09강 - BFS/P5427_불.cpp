#include<bits/stdc++.h>
using namespace std;

#define Y first
#define X second

char Map[1001][1001];
int fireVisited[1001][1001] = {0, };
int playerVisited[1001][1001] = {0, };
int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};
bool isComplete = false;

int w, h;

queue<pair<int, int>> firePos;
queue<pair<int, int>> playerPos;

void fire()
{
    int qsize = firePos.size();
    while(qsize--)
    {
        int y = firePos.front().Y;
        int x = firePos.front().X;
        firePos.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if(!fireVisited[ny][nx] && Map[ny][nx] != '#')
            {
                fireVisited[ny][nx] = 1;
                Map[ny][nx] = '*';
                firePos.push({ny, nx});
            }
        }
    }
}

void move()
{
    int qsize = playerPos.size();
    while(qsize--)
    {
        int y = playerPos.front().Y;
        int x = playerPos.front().X;
        playerPos.pop();
        
        if(y == 0 || y == h-1 || x == 0 || x == w-1) isComplete = true;

        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if(!playerVisited[ny][nx] && Map[ny][nx] == '.')
            {
                playerVisited[ny][nx] = 1;
                Map[ny][nx] = '%';
                playerPos.push({ny, nx});
            }
        }

    }
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        cin >> w >> h;
        isComplete = false;
        firePos = queue<pair<int, int>>();
        playerPos = queue<pair<int, int>>();

        for(int y = 0; y < h; y++)
            for(int x = 0; x < w; x++)
            {
                fireVisited[y][x] = 0;
                playerVisited[y][x] = 0;
                cin >> Map[y][x];
                if(Map[y][x] == '*')
                {
                    fireVisited[y][x] = 1;
                    firePos.push({y, x});
                }
                else if(Map[y][x] == '@')
                {
                    playerVisited[y][x] = 1;
                    playerPos.push({y, x});
                }
            }
        int count = 0;
        while(!playerPos.empty() && !isComplete)
        {   
            count++;
            fire();
            move();
        }
        if(isComplete) cout << count << "\n";
        else cout << "IMPOSSIBLE\n";
    }
}