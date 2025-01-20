#include<bits/stdc++.h>
using namespace std;

const int MX = 10000;
int dq[2 * MX + 1] = {-1, };
int head = MX;
int tail = MX;

void push_back(int a)
{
    dq[tail++] = a;
}
void push_front(int a)
{   
    dq[--head] = a;
}
void pop_front()
{
    head++;
}
void pop_back()
{
    tail--;
}
int front()
{
    return dq[head];
}
int back()
{
    return dq[tail-1];
}


int main()
{
    // Deque 직접 구현
    // cout << front() << "\n";
    // push_front(123);
    // cout << front() << "\n";
    // push_back(12113);
    // cout << front() << "\n";

    //STL
    deque<int> DQ;
    DQ.push_back(1);
    DQ.push_back(4);
    DQ.push_front(2224);
    cout << DQ.front() << "\n";
    cout << DQ.back() << "\n";
    DQ.pop_front();
    DQ.pop_front();
    cout << DQ.back() << "\n";


}
