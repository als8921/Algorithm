#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    int count[26] = {0, };
    cin >> a >> b;

    for (int i = 0;  i < (int)a.length(); i++)
        count[a[i] - 'a']++;

    for (int i = 0;  i < (int)b.length(); i++)
        count[b[i] - 'a']--;

    int ans = 0;
    for (int i = 0; i < 26; i++)
        ans += abs(count[i]);

    cout << ans;
}