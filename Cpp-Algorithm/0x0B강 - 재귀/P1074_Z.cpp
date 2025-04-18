#include<bits/stdc++.h>
using namespace std;

int check(int N, int row, int col){
    if(N == 0) return row * 2 + col;
    int result = 0;

    int rowDivide = row / int(pow(2, N));
    int colDivide = col / int(pow(2, N));

    int rowMod = row % int(pow(2, N));
    int colMod = col % int(pow(2, N));

    // 1
    if(rowDivide == 0 && colDivide == 0){
        result = 0;
    }
    // 2
    else if(rowDivide == 0 && colDivide == 1){
        result = int(pow(2, 2 * N));
    }
    // 3
    else if(rowDivide == 1 && colDivide == 0){
        result = 2 * int(pow(2, 2 * N));
    }
    // 4
    else if(rowDivide == 1 && colDivide == 1){
        result = 3 * int(pow(2, 2 * N));
    }
    return result + check(N-1, rowMod, colMod);
}


int main(){
    int N, r, c;
    cin >> N >> r >> c;
    cout << check(N-1, r, c) << "\n";
}