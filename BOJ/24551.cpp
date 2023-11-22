#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b){
    return b ? gcd(b, a % b) : a;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    vector<long long> arr(16);
    arr[0] = 11;

    for(int i = 1; i < 16; i++){
        arr[i] = 10 * arr[i - 1] + 1;
    }

    long long answer = 0;
    for(int i = 1; i < (1 << 16); i++){
        long long lcm = 1;
        for(int j = 0; j < 16; j++){
            if(i & (1 << j)){
                long long g = gcd(lcm, arr[j]);
                if(lcm <= n / (arr[j] / g)){
                    lcm = lcm * (arr[j] / g);
                }else{
                    lcm = 1e18 + 1;
                    break;
                }
            }
            if(lcm > n){
                break;
            }
        }
        if(lcm > n){
            continue;
        }
        if(__builtin_popcount(i) % 2){
            answer += n / lcm;
        }else{
            answer -= n / lcm;
        }
    }

    cout << answer;

    return 0;
}