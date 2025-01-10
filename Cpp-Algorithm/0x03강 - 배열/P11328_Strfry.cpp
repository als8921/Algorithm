#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string a, b;
        int countA[26] = {0, };
        int countB[26] = {0, };
        cin >> a >> b;

        for (int i = 0;  i < (int)a.length(); i++)
            countA[(int)a[i] - 97]++;

        for (int i = 0;  i < (int)b.length(); i++)
            countB[(int)b[i] - 97]++;

        bool isAble = true;
        for (int i = 0; i < 26; i++)
            if(countA[i] != countB[i]) isAble = false;

        if(isAble) cout << "Possible"<<"\n";
        else cout << "Impossible"<<"\n";
    }
}