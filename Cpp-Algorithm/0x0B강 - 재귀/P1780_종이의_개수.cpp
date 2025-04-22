#include <bits/stdc++.h>

using namespace std;

int graph[2187][2187];
int n_zero = 0;
int n_one = 0;
int n_minusone = 0;

int check(int y_start, int x_start, int size)
{
    if(size == 1) return graph[y_start][x_start];
    int num = graph[y_start][x_start];
    for(int y = y_start; y < y_start + size; y++)
        for(int x = x_start; x < x_start + size; x++)
        {
            if(graph[y][x] != num) return -2;
        }
    return num;
}


void search(int y_start, int x_start, int size)
{
    int n = check(y_start, x_start, size);
    if(n == 0) {n_zero++; return;}
    else if(n == -1) {n_minusone++; return;}
    else if(n == 1) {n_one++; return;}

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            search(y_start + i * (size/3), x_start + j * (size/3), size/3);
}

int main()
{
    int n; cin >> n;
    for(int y = 0; y < n; y++)
        for(int x = 0; x < n; x++)
            cin >> graph[y][x];

    search(0, 0, n);

    cout << n_minusone << "\n";
    cout << n_zero << "\n";
    cout << n_one << "\n";
}