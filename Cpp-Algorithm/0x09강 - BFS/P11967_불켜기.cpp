#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int main()
{
    int n, m; cin >> n >> m;

    vector<pair<int, int>> connected[100][100];
    bool lightMap[100][100];
    bool visited[100][100];

    fill(&lightMap[0][0], &lightMap[0][0] + 10000, false);
    fill(&visited[0][0], &visited[0][0] + 10000, false);

    while(m--)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        x--; y--; a--; b--;
        connected[y][x].push_back({b, a});
    }
    cout<<"--------------------------\n";

    int result = 1;
    queue<pair<int, int>> q;
    q.push({0, 0});
    lightMap[0][0] = true;
    visited[0][0] = true;
    while(!q.empty())
    {
        int y, x;
        y = q.front().first;
        x = q.front().second;
        q.pop();
        visited[y][x] = true;
        
        cout << y  << ", " << x << "\n";
        for(pair<int, int> pos : connected[y][x])
        {
            int ly = pos.first;
            int lx = pos.second;
            if(lightMap[ly][lx]) continue;
            
            lightMap[ly][lx] = true;
            result++;
            for(int i = 0; i < 4; i++)
            {
                int ny = ly + dy[i];
                int nx = lx + dx[i];
    
                if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                if(visited[ny][nx]) {q.push({ly, lx}); break;}
            }
        }

        
        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if(lightMap[ny][nx] && !visited[ny][nx]) q.push({ny, nx});
        }

    }

    cout<<"light--------------------------\n";
    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < n; x++)
        {
            cout<< lightMap[y][x] << " ";
        }
        cout << "\n";
    }
    cout<<"visited--------------------------\n";
    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < n; x++)
        {
            cout<< visited[y][x] << " ";
        }
        cout << "\n";
    }
    cout << result <<" : result\n"; 
}