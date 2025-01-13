#include<bits/stdc++.h>
using namespace std;

const int n = 10;
int dat[n], pre[n], nxt[n];
int unused = 0;
void setData()
{
    fill(dat, dat + n, -1);
    fill(pre, pre + n, -1);
    fill(nxt, nxt + n, -1);

    dat[0] = -1; pre[0] = -1; nxt[0] = 2;
    dat[1] = 65; pre[1] = 2; nxt[1] = 4;
    dat[2] = 13; pre[2] = 0; nxt[2] = 1;
    dat[4] = 21; pre[4] = 1; nxt[4] = 5;
    dat[5] = 17; pre[5] = 4; nxt[5] = -1;
    unused = 6;
}
void traverse()
{
    int point = nxt[0];
    while(point != -1)
    {
        cout << pre[point] <<"["<< point <<"] "<< dat[point] << "  " << nxt[point] << "\n";
        point = nxt[point];
    }
    cout << "\n\n";
}
void insert(int addr, int num){
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if(nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}
void erase(int addr){
    nxt[pre[addr]] = nxt[addr];
    if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}
int main()
{
    /*
    직접 구현하기
    setData();
    traverse();
    insert(5, 444);
    traverse();
    erase(5);
    traverse();
    */

   //STL
   list<int> L = {1, 2};
   list<int>::iterator t = L.begin();
//    auto t = L.begin();
   L.push_back(5);
   L.insert(t, 10); //t가 가리키는 곳 앞에 10 추가
   t++;
   t = L.erase(t); //t가 가리키는 원소 삭제, 다음 원소의 위치 반환
   for(int e : L)
   cout << e << "\n";
}
