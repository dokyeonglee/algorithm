#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b){
    return b ? gcd(b, a % b) : a;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> arr(k);
    for(int i = 0; i < k; i++){
        cin >> arr[i];
    }

    int answer = 0;

    for(int i = 1; i < (1 << k); i++){
        long long lcm = 1;
        for(int j = 0; j < k; j++){
            if(i & (1 << j)){
                lcm = arr[j] * lcm / gcd(lcm, arr[j]);
                if(lcm > n){
                    break;
                }
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