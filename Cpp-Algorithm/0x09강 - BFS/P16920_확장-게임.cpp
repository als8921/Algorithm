#include <bits/stdc++.h>
using namespace std;

#define Y first;
#define X second;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int N, M, P;
int S[10] = {0, };
char graph[1001][1001];
int visited[1001][1001];

int result[10] = {0, };

bool expand(int playerIdx)
{
    queue<pair<int, int>> Q;
    int startIdx = 1;
    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < M; x++)
        {
            if(graph[y][x] - 48 == playerIdx && (visited[y][x] == 0 || visited[y][x] == startIdx + S[playerIdx]))
            {
                visited[y][x] = startIdx;
                Q.push({y, x});
            }
        }
    }
    if(Q.empty()) return true;

    while(!Q.empty())
    {
        int y = Q.front().Y;
        int x = Q.front().X;
        Q.pop();

        if(visited[y][x] >= startIdx + S[playerIdx]) continue;
        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(graph[ny][nx] == '.' && visited[ny][nx] == 0)
            {
                visited[ny][nx] = visited[y][x] + 1;
                graph[ny][nx] = (char)(playerIdx + 48);
                Q.push({ny, nx});
            }
        }
    }
    return false;
}
void countResult()
{
    for(int y = 0; y < N ; y++)
    {
        for(int x = 0; x < M; x++)
        {
            int i = graph[y][x] - 48;
            if(i > 0 && i <= 9) result[i]++;
        }
    }
    for(int i = 1; i < P + 1; i++)
        cout << result[i] << " ";
    cout << "\n";

}
void showVisited()
{
    cout << "visited : \n";
    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < M; x++)
        {
            cout << visited[y][x] << " ";
        }
        cout << "\n";
    }
}
void showGraph()
{
    cout << "graph : \n";
    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < M; x++)
        {
            cout << graph[y][x];
        }
        cout << "\n";
    }
}
void initialize()
{
    cin >> N >> M >> P;
    for(int i = 1; i < P + 1; i++) cin >> S[i];

    for(int y = 0; y < N; y++)
        for(int x = 0; x < M; x++)
            cin >> graph[y][x];

    fill(&visited[0][0], &visited[0][0] + 1001 * 1001, 0);
}
int main()
{
    initialize();

    while(1){
        int temp = 0;
        for(int i = 1; i < P + 1; i++)
            temp += expand(i);
        if(temp == P) break;
    }

    countResult();
}