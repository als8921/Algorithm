#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    int graph[n][n];
    int dp[n+1][n+1];
    fill(&graph[0][0], &graph[0][0] + n * n, 0);
    fill(&dp[0][0], &dp[0][0] + (n+1) * (n+1), 0);

    for(int y = 0; y < n; y++)
        for(int x = 0; x < n; x++)
            cin >> graph[x][y];
 
    for(int y = 0; y < n; y++)
        for(int x = 0; x < n; x++)
            dp[y+1][x+1] = dp[y][x+1] + dp[y+1][x] + graph[y][x] - dp[y][x];

    while(m--)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int result = dp[y2][x2] - dp[y1 - 1][x2] - dp[y2][x1 - 1] + dp[y1 - 1][x1 - 1];
        cout << result << "\n";
    }
}