#include<bits/stdc++.h>
using namespace std;
int main()
{
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;

    int visited[F+1] = {0, };
    queue<int> Q;

    Q.push(S);
    visited[S] = 1;

    while(!Q.empty())
    {
        int current = Q.front();
        if(current == G)
        {
            cout << visited[current] - 1 << "\n";
            return 0;
        }
        Q.pop();
        if(current + U >= 1 && current + U <= F && !visited[current + U])
        {
            Q.push(current + U);
            visited[current + U] = visited[current] + 1;
        }
        if(current - D >= 1 && current - D <= F && !visited[current - D])
        {
            Q.push(current - D);
            visited[current - D] = visited[current] + 1;
        }
    }
    cout << "use the stairs\n";
}
