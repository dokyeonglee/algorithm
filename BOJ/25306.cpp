#include <iostream>
#include <vector>

using namespace std;

long long solve(long long n){
    if(n % 4 == 0){
        return n;
    }else if(n % 4 == 1){
        return 1;
    }else if(n % 4 == 2){
        return n + 1;
    }else{
        return 0;
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long a, b;
    cin >> a >> b;

    cout << (solve(a - 1) ^ solve(b));

    return 0;
}   