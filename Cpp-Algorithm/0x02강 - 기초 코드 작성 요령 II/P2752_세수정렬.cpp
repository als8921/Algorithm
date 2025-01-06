#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[3] = {0,};
    cin >> a[0] >> a[1] >> a[2];

    int max = a[0];
    int min = a[0];

    for(int i = 1; i < 3; i++)
    {
        if(a[i] > max)
            max = a[i];
        if(a[i] < min)
            min = a[i];
    }

    int remain = 0;
    for(int i = 0; i < 3; i++)
    {   
        if(a[i] != min && a[i] != max)
        {
            remain = a[i];
            break;
        }
    }
    cout << min << " " << remain << " " <<  max << "\n";
}