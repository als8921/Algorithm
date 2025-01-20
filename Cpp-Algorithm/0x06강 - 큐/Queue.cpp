#include<bits/stdc++.h>
using namespace std;


int s[10000] = {-1, };
int head = 0;
int tail = 0;

void pop();
void push(int a);
int front();

int main()
{
    // 큐 직접 구현
    
    // cout << front() << "\n";
    // push(1222);
    // push(53);
    // push(2131);
    // cout << front() << "\n";
    // pop();
    // cout << front() << "\n";
    // pop();
    // cout << front() << "\n";


    //STL
    queue<int> Q;
    cout << Q.front() << "\n";
    Q.push(1);
    Q.push(5);
    Q.push(6);
    cout << Q.front() << "\n";
    Q.pop();
    cout << Q.front() << "\n";
    Q.pop();
    cout << Q.front() << "\n";
    Q.pop();
    cout << Q.front() << "\n";
}

void pop()
{
    if(head < tail) head++;
}
void push(int a)
{
    s[tail++] = a;
}
int front()
{
    return s[head];
}