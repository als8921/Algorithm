#include<bits/stdc++.h>
using namespace std;


int s[10000] = {0, };
int point = -1;

void pop();
void push(int a);
int top();

int main()
{
    // 스택 직접 구현
    cout << top() << "\n";
    push(1222);
    cout << top() << "\n";
    pop();
    pop();
    cout << top() << "\n";

    //STL
    stack<int> S;
    S.push(1);
    cout << S.top() << "\n";
    S.pop();
}

void pop()
{
    if(point >= 0) point--;
    else cout << "Stack Is Empty\n";
}
void push(int a)
{
    s[++point] = a;
}
int top()
{
    if(point >= 0)
        return s[point];

    else return -1;
}