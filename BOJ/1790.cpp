#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    long long answer = 0;
    long long t = 9;
    long long x = 1;

    while(k > t * x){
        answer += t;
        k -= t * x;
        t *= 10;
        x++;
    }

    answer += (k - 1) / x + 1;

    if(answer > n){
        cout << -1;
    }else{
        cout << to_string(answer).at((k - 1) % x);
    }

    return 0;
}