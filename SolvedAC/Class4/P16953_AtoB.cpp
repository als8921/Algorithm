#include <bits/stdc++.h>

using namespace std;

int result = -1;
void bfs(long long n, int goal, int depth)
{
    if(n == goal) result = depth;
    else if(n > goal) return;
    else
    {
        bfs(n * 2, goal, depth + 1);
        bfs(n * 10 + 1, goal, depth + 1);
    }
}

int main()
{
    int a, b;
    cin >> a >> b;

    bfs(a, b, 1);
    cout << result << "\n";
}