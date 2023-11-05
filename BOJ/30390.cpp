#include <iostream>
#include <vector>

using namespace std;

bool possible(long long a, long long b, long long k, long long x){
    return min(a % x, b % x) <= k;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long a, b, k;
    cin >> a >> b >> k;

    long long n = a + b;

    long long answer = -1;

    for(long long i = 1; i * i <= n; i++){
        if(n % i == 0){
            if(possible(a, b, k, n / i)){
                answer = n / i;
                break;
            }else if(possible(a, b, k, i)){
                answer = i;
            }
        }
    }

    cout << answer;

    return 0;
}