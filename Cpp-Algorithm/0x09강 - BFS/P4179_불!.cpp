#include<bits/stdc++.h>
using namespace std;

#define Y first
#define X second

char m[1001][1001];
bool visited_player[1001][1001];
bool visited_fire[1001][1001];
int height, length;

bool isEscape = false;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

queue<pair<int, int>> firePos;
queue<pair<int, int>> playerPos;

void fireSpread()
{
    int qsize = firePos.size();

    while(qsize--)
    {
        pair<int, int> pos = firePos.front(); firePos.pop();
        int y = pos.Y;
        int x = pos.X;
        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= height || nx < 0 || nx >= length || visited_fire[ny][nx]) continue;
            if(m[ny][nx] == '.')
            {
                visited_fire[ny][nx] = true;
                m[ny][nx] = 'F';
                firePos.push({ny, nx});
            }
        }
    }

}

void Move()
{
    int qsize = playerPos.size();
    while(qsize--)
    {
        pair<int, int> pos = playerPos.front(); playerPos.pop();
        int y = pos.Y;
        int x = pos.X;
        if(y == 0 || y == height - 1 || x == 0 || x == length - 1)
        {
            isEscape = true;
            return;
        }


        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= height || nx < 0 || nx >= length || visited_player[ny][nx]) continue;
            if(m[ny][nx] == '.')
            {
                visited_player[ny][nx] = true;
                playerPos.push({ny, nx});
            }
        }
    }
}

void printMap()
{

    cout << "----------------------- MAP --------------------------\n";
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < length; j++)
            cout << m[i][j];
        cout << "\n";
    }
}
int main()
{
    for(int i = 0; i < height; i++)
        for(int j = 0; j < length; j++)
        {
            visited_player[i][j] = false;
            visited_fire[i][j] = false;
        }

    cin >> height >> length;
    for(int i = 0; i < height; i++)
        for(int j = 0; j < length; j++)
            {
                cin >> m[i][j];
                if(m[i][j] == 'F')
                { 
                    firePos.push({i, j});
                    visited_fire[i][j] = true;
                }
                else if(m[i][j] == 'J') 
                {
                    playerPos.push({i, j});
                    visited_player[i][j] = true;
                }
                
            }

    int i = 0;
    while(!playerPos.empty() && !isEscape){
        fireSpread();
        Move();
        // printMap();
        i++;
    }
    if(isEscape)
        cout << i << "\n";
    else
        cout << "IMPOSSIBLE\n";
}

/*
1. 불이 퍼지는 함수
2. 불의 가장자리를 vector에 담기
3. 한 칸 이동 한 위치를 담기


*/