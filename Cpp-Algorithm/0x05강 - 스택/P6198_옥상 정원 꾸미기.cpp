// https://www.acmicpc.net/problem/6198
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> height;
    long long result = 0;
    for(int i = 0; i < N; i++)
    {
        int h;
        cin >> h;
        height.push_back(h);
    }
    for (int i = 0; i < (int)height.size(); i++)
    {
        for (int j = i + 1; j < (int)height.size(); j++)
        {
            if(height[i] > height[j]) result++;
            else break;
        }
    }
    cout << result;
}

/*
10  3  7  4  12 2
이전 수 보다 작으면 +1


10  3   7   4   12  2




6 : 0
5 : 1 0
4 : 
3 : 
2 : 
1 : 
*/