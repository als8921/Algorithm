#include <bits/stdc++.h>
using namespace std;
int N;
bool starMap[3072 + 1][3072 * 2] = {false, };

void setStar(int y, int x, int s){
    if(s == 3)
    {
        starMap[y-2][x-2] = true;
        starMap[y-1][x-3] = true;
        starMap[y-1][x-1] = true;
        for(int i = 0; i < 5; i++)
            starMap[y][x-i] = true;
    }
    else{
        setStar(y - s/2 , x - s/2, s/2);
        setStar(y, x - s,s/2);
        setStar(y, x,s/2);
    }
}
void drawStar(){
    for(int y = 0; y < N; y++){
        for(int x = 0; x < 2*N - 1; x++){
            if(starMap[y][x]) cout << "*";
            else cout << " ";
        }
        cout << "\n";
    }
}
int main(){
    cin >> N;
    setStar(N-1, 2*N - 2, N);
    drawStar();
}