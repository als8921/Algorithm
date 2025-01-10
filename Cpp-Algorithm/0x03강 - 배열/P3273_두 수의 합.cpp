#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n;
    int num[n] = {0, };
    int a[1000001] = {0, };

    for (int i = 0; i < n; i++) 
    {   
        int temp;
        cin >> temp;
        num[i] = temp;
        a[temp]++;
    }
    cin >> x;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(x - num[i] == num[i])
        {
            if(a[x - num[i]] > 1)
                count++;
        }
        else
        {
            if(x - num[i] > 0 && x - num[i] < 1000001 && a[x - num[i]])
                count ++;
        }
    }
    cout << (int)count/2;
}