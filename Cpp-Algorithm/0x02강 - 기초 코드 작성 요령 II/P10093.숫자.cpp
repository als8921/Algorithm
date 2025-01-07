#include<bits/stdc++.h>
using namespace std;

void swap(long long *a, long long *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    long long start, end;
    cin >> start >> end;

    if(start > end){
        swap(start, end);
    }

    if(start == end) cout << "0" << "\n";
    else cout << end - start - 1 << "\n";
    for (long long i = start + 1; i < end; i++)
    {
        cout << i << " ";
    }
}