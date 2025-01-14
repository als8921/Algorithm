// https://www.acmicpc.net/problem/2493
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    list<int> resultList = {};
    stack<vector<int>> hStack;
    for(int i = 1; i < n + 1; i++)
    {
        int h;
        cin >> h;
        int result = 0;
        while(!hStack.empty())
        {
            if(hStack.top()[1] < h)
                hStack.pop();
            else if(hStack.top()[1] >= h)
            {
                result = hStack.top()[0];
                break;
            }
        }
        resultList.push_back(result);
        hStack.push({i, h});
    }
    for(int e : resultList)
    cout << e << " "; 
}
/*
1. 높이를 담는 배열 만들기
2. 하나씩 입력 받음
    이전에 높이를 탐색하며 자신 이상인 값을 찾음
        없으면 0을 result에 저장
        있으면 그 idx를 result에 저장
--- 시간 초과 ---
stack<vector<int>> [idx, height]
값이 들어옴
    stack에 자신보다 낮은 높이가 있다면 pop
    stack에 자신과 같거나 높은 높이가 있다면 result = 그 높이
    stack이 비어있다면 result = 0, 자신을 추가
--- 성공 ---
*/