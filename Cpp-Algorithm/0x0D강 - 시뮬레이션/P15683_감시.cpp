#include <bits/stdc++.h>
using namespace std;

int h, w;
char cctvPos[9][9];
char graph[9][9];
int result = 64;
int dir[6] = {0, 4, 2, 4, 4, 1};
vector<vector<int>> cctvList;

void cctv1(int cy, int cx, int dir)
{
    switch (dir)
    {
    case 0:
        for(int x = cx + 1; x < w; x++)
        {
            if(cctvPos[cy][x] == '6') break;
            graph[cy][x] = '#';
        }
        break;
    case 1:
        for(int y = cy + 1; y < h; y++)
        {
            if(cctvPos[y][cx] == '6') break;
            graph[y][cx] = '#';
        }
        break;
    case 2:
        for(int x = cx - 1; x >= 0; x--)
        {
            if(cctvPos[cy][x] == '6') break;
            graph[cy][x] = '#';
        }
        break;
    case 3:
        for(int y = cy - 1; y >= 0; y--)
        {
            if(cctvPos[y][cx] == '6') break;
            graph[y][cx] = '#';
        }
        break;
    default:
        break;
    }
}
void cctv2(int cy, int cx, int dir)
{
    switch (dir)
    {
    case 0:
        for(int x = cx + 1; x < w; x++)
        {
            if(cctvPos[cy][x] == '6') break;
            graph[cy][x] = '#';
        }
        for(int x = cx - 1; x >= 0; x--)
        {
            if(cctvPos[cy][x] == '6') break;
            graph[cy][x] = '#';
        }
        break;
    case 1:
        for(int y = cy + 1; y < h; y++)
        {
            if(cctvPos[y][cx] == '6') break;
            graph[y][cx] = '#';
        }
        for(int y = cy - 1; y >= 0; y--)
        {
            if(cctvPos[y][cx] == '6') break;
            graph[y][cx] = '#';
        }
        break;
    default:
        break;
    }
}
void cctv3(int cy, int cx, int dir)
{
    switch (dir)
    {
    case 0:
        for(int y = cy + 1; y < h; y++)
        {
            if(cctvPos[y][cx] == '6') break;
            graph[y][cx] = '#';
        }
        for(int x = cx + 1; x < w; x++)
        {
            if(cctvPos[cy][x] == '6') break;
            graph[cy][x] = '#';
        }
        break;
    case 1:
        for(int y = cy + 1; y < h; y++)
        {
            if(cctvPos[y][cx] == '6') break;
            graph[y][cx] = '#';
        }
        for(int x = cx - 1; x >= 0; x--)
        {
            if(cctvPos[cy][x] == '6') break;
            graph[cy][x] = '#';
        }
        break;
    case 2:
        for(int y = cy - 1; y >= 0; y--)
        {
            if(cctvPos[y][cx] == '6') break;
            graph[y][cx] = '#';
        }
        for(int x = cx - 1; x >= 0; x--)
        {
            if(cctvPos[cy][x] == '6') break;
            graph[cy][x] = '#';
        }
        break;
    case 3:
        for(int y = cy - 1; y >= 0; y--)
        {
            if(cctvPos[y][cx] == '6') break;
            graph[y][cx] = '#';
        }
        for(int x = cx + 1; x < w; x++)
        {
            if(cctvPos[cy][x] == '6') break;
            graph[cy][x] = '#';
        }
        break;
    default:
        break;
    }
}
void cctv4(int cy, int cx, int dir)
{
    switch (dir)
    {
    case 0:
        for(int x = cx + 1; x < w; x++)
        {
            if(cctvPos[cy][x] == '6') break;
            graph[cy][x] = '#';
        }
        for(int y = cy + 1; y < h; y++)
        {
            if(cctvPos[y][cx] == '6') break;
            graph[y][cx] = '#';
        }
        for(int y = cy - 1; y >= 0; y--)
        {
            if(cctvPos[y][cx] == '6') break;
            graph[y][cx] = '#';
        }
        break;
    case 1:
        for(int y = cy + 1; y < h; y++)
        {
            if(cctvPos[y][cx] == '6') break;
            graph[y][cx] = '#';
        }
        for(int x = cx + 1; x < w; x++)
        {
            if(cctvPos[cy][x] == '6') break;
            graph[cy][x] = '#';
        }
        for(int x = cx - 1; x >= 0; x--)
        {
            if(cctvPos[cy][x] == '6') break;
            graph[cy][x] = '#';
        }
        break;
    case 2:
        for(int x = cx - 1; x >= 0; x--)
        {
            if(cctvPos[cy][x] == '6') break;
            graph[cy][x] = '#';
        }
        for(int y = cy + 1; y < h; y++)
        {
            if(cctvPos[y][cx] == '6') break;
            graph[y][cx] = '#';
        }
        for(int y = cy - 1; y >= 0; y--)
        {
            if(cctvPos[y][cx] == '6') break;
            graph[y][cx] = '#';
        }
        break;
    case 3:
        for(int y = cy - 1; y >= 0; y--)
        {
            if(cctvPos[y][cx] == '6') break;
            graph[y][cx] = '#';
        }
        for(int x = cx + 1; x < w; x++)
        {
            if(cctvPos[cy][x] == '6') break;
            graph[cy][x] = '#';
        }
        for(int x = cx - 1; x >= 0; x--)
        {
            if(cctvPos[cy][x] == '6') break;
            graph[cy][x] = '#';
        }
        break;
    default:
        break;
    }
}
void cctv5(int cy, int cx, int dir)
{
    switch (dir)
    {
    case 0:
        for(int x = cx + 1; x < w; x++)
        {
            if(cctvPos[cy][x] == '6') break;
            graph[cy][x] = '#';
        }
        for(int x = cx - 1; x >= 0; x--)
        {
            if(cctvPos[cy][x] == '6') break;
            graph[cy][x] = '#';
        }
        for(int y = cy + 1; y < h; y++)
        {
            if(cctvPos[y][cx] == '6') break;
            graph[y][cx] = '#';
        }
        for(int y = cy - 1; y >= 0; y--)
        {
            if(cctvPos[y][cx] == '6') break;
            graph[y][cx] = '#';
        }
        break;
    default:
        break;
    }
}

void resetGraph()
{
    for(int i = 0; i < h; i++)
        strcpy(graph[i], cctvPos[i]);
}

int countSpace()
{
    int count = 0;
    for(int y = 0; y < h; y++)
        for(int x = 0; x < w; x++)
            if(graph[y][x] == '0') count++;
    
    return count;
}
void dfs(int depth)
{
    if(depth == cctvList.size())
    {
        result = min(result, countSpace());
        return;
    }

    int cctvType = cctvList[depth][0];
    int y = cctvList[depth][1];
    int x = cctvList[depth][2];

    char temp[8][8];
    
    for(int i = 0; i < h; i++)
        strcpy(temp[i], graph[i]);

    if(cctvType == 1)
    {
        for(int i = 0; i < dir[1]; i++){
            cctv1(y, x, i);
            dfs(depth + 1);
            for(int i = 0; i < h; i++)
                strcpy(graph[i], temp[i]);
        }
    }
    else if(cctvType == 2)
    {
        for(int i = 0; i < dir[2]; i++){
            cctv2(y, x, i);
            dfs(depth + 1);
            for(int i = 0; i < h; i++)
                strcpy(graph[i], temp[i]);
        }
    }
    else if(cctvType == 3)
    {
        for(int i = 0; i < dir[3]; i++){
            cctv3(y, x, i);
            dfs(depth + 1);
            for(int i = 0; i < h; i++)
                strcpy(graph[i], temp[i]);
        }
    }
    else if(cctvType == 4)
    {
        for(int i = 0; i < dir[4]; i++){
            cctv4(y, x, i);
            dfs(depth + 1);
            for(int i = 0; i < h; i++)
                strcpy(graph[i], temp[i]);
        }
    }
    else if(cctvType == 5)
    {
        for(int i = 0; i < dir[5]; i++){
            cctv5(y, x, i);
            dfs(depth + 1);
            for(int i = 0; i < h; i++)
                strcpy(graph[i], temp[i]);
        }
    }
}
int main()
{
    cin >> h >> w;
    for(int y = 0; y < h; y++)
        for(int x = 0; x < w; x++)
        {
            cin >> cctvPos[y][x];
            if(cctvPos[y][x] == '1') cctvList.push_back({1, y, x});
            else if(cctvPos[y][x] == '2') cctvList.push_back({2, y, x});
            else if(cctvPos[y][x] == '3') cctvList.push_back({3, y, x});
            else if(cctvPos[y][x] == '4') cctvList.push_back({4, y, x});
            else if(cctvPos[y][x] == '5') cctvList.push_back({5, y, x});
        }
    
    resetGraph();
    dfs(0);
    cout << result << "\n";
}