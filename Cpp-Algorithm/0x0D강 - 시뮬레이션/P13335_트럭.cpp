#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, W, L;
    cin >> N >> W >> L;
    int a[N];
    queue<int> Q;
    int sum = 0;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < W; i++) Q.push(0);

    int count = 0;
    int i = 0;
    while(1)
    {
        count++;
        if(i >= N) break;
        int front = Q.front(); Q.pop();
        sum -= front;

        if(sum + a[i] <= L){
            sum += a[i];
            Q.push(a[i++]);
        }
        else
            Q.push(0);
    }
    count += W - 1;
    cout << count << "\n";
}