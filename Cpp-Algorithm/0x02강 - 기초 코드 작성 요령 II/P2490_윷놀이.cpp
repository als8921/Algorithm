#include<bits/stdc++.h>
using namespace std;

int main(){
    for(int i = 0; i < 3; i++)
    {
        int a[4];
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        
        int sum = a[0] + a[1] + a[2] + a[3];

        if(sum == 0) cout << "D" << "\n";
        else if(sum == 1) cout << "C" << "\n";
        else if(sum == 2) cout << "B" << "\n";
        else if(sum == 3) cout << "A" << "\n";
        else if(sum == 4) cout << "E" << "\n";
    }
}