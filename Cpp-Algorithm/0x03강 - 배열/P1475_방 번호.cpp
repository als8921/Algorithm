#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(11, 0);

    while(n > 0)
    {   
        if(n%10 == 9 && v[6] < v[9]) v[6] += 1;
        else if(n%10 == 6 && v[6] > v[9]) v[9] += 1;
        else v[n%10] += 1;
        n /= 10;
    }

    int max = 0;
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] > max) max = v[i];
    }
    cout << max;
}