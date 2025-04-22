#include <bits/stdc++.h>

using namespace std;

char graph[64][64];
int n_zero = 0;
int n_one = 0;

char check(int y_start, int x_start, int size)
{
    if(size == 1) return graph[y_start][x_start];
    char num = graph[y_start][x_start];
    for(int y = y_start; y < y_start + size; y++)
        for(int x = x_start; x < x_start + size; x++)
        {
            if(graph[y][x] != num) return -1;
        }
    return num;
}


void search(int y_start, int x_start, int size)
{
    char n = check(y_start, x_start, size);
    if(n == '0') {cout << "0"; return;}
    else if(n == '1') {cout << "1"; return;}

    cout << "(";
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            search(y_start + i * (size/2), x_start + j * (size/2), size/2);
    cout << ")";
}

int main()
{
    int n; cin >> n;
    for(int y = 0; y < n; y++)
        for(int x = 0; x < n; x++)
            cin >> graph[y][x];

    search(0, 0, n);
    cout << "\n";
}