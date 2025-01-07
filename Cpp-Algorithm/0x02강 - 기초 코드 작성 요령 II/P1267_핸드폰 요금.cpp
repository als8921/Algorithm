#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    int y = 0;
    int m = 0;
    for (int i = 0; i < n; i++)
    {   
        cin >> a[i];
        if(a[i] <= 29) y += 10;
        else if(a[i] <= 59) y += 20;
        else y += 10 * (int)(1 + a[i] / 30);

        if(a[i] <= 59) m += 15;
        else if(a[i] <= 119) m += 30;
        else m += 15 * (int)(1 + a[i] / 60);
    }
    if(y < m) cout <<"Y " << y;
    else if(m < y) cout <<"M " << m;
    else cout << "Y " << "M " << y;
}