#include<bits/stdc++.h>
using namespace std;

long long multiply(long long number, long long multiply_cnt, long long mod_number){
    if(multiply_cnt == 1) return number % mod_number;
    if(multiply_cnt % 2 == 0){
        long long a = multiply(number, multiply_cnt / 2, mod_number);
        return (a * a) % mod_number;
    }
    else if(multiply_cnt % 2 == 1){
        long long a = multiply(number, multiply_cnt / 2, mod_number);
        return ((a * a) % mod_number * number) % mod_number;
    }
    return 0;
}

int main(){

    long long a, b, c;
    cin >> a >> b >> c;

    long long result = multiply(a, b, c);
    cout << result << "\n";
}
