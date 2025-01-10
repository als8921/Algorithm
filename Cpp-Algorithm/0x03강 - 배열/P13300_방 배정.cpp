#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[7][2] = {0, };
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        int s, grade;
        cin >> s >> grade;
        a[grade][s]++;
    }

    int ans = 0;
    for(int i = 1; i <= 6; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            if(a[i][j] % m)
                ans += a[i][j]/m + 1;
            else
                ans += a[i][j]/m;
        }
    }
    cout << ans;
}