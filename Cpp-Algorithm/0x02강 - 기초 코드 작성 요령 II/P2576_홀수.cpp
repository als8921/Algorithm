#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[7];
    for (int i = 0; i < 7; ++i) {
        cin >> a[i];
    }
    int min = 101;
    int sum = 0;
    for (int i = 0; i < 7; i++)
    {
       if(a[i] % 2 == 1)
       {
            sum += a[i];
            if(a[i] < min) min = a[i];
       }
    }
    if(min == 101) cout << "-1";
    else cout << sum << "\n" << min;
}