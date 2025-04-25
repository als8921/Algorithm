#include <bits/stdc++.h>
using namespace std;

int n; 
int visited[15];

int result = 0;

bool check(int y, int x)
{
    for(int xx = 0; xx < n; xx++)
    {
        int yy = visited[xx];
        if(yy == -1) continue;
        if(y == yy || x == xx || y - x == yy - xx || y + x == yy + xx) return false;
    }
    return true; 
}

void search(int i)
{
    if(i == n) 
    {
        result++;
        return;
    }
    for(int x = 0; x < n; x++)
    {
        if(check(i, x))
        {
            visited[x] = i; 
            search(i+1);
            visited[x] = -1;
        }
    }
}
int main()
{
    cin >> n;
    fill(&visited[0], &visited[0] + 15, -1);
    search(0);

    cout << result << "\n";
}