#include <iostream>
#include <vector>

using namespace std;

long long pow(long long a, long long n, long long mod){
    long long result = 1;
    while(n > 0){
        if(n & 1){
            result = a * result % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n + 1);
    vector<int> psum(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        psum[i] = psum[i - 1] + arr[i];
    }

    vector<long long> answer(n + 2);

    const int mod = 1e9 + 7;

    while(q--){
        int l, r;
        cin >> l >> r;
        auto temp = pow(psum[r] - psum[l - 1], mod - 2, mod);
        answer[l] += temp;
        answer[r + 1] -= temp;
    }

    for(int i = 1; i <= n; i++){
        answer[i] += answer[i - 1];
    }

    for(int i = 1; i <= n; i++){
        answer[i] %= mod;
        answer[i] *= arr[i] * (arr[i] - 1);
        answer[i] %= mod;
    }

    for(int i = 1; i <= n; i++){
        cout << answer[i] << " ";
    }

    return 0;
}