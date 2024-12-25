#include <iostream>
#include <vector>

using namespace std;

long long pow(long long a, long long n, long long mod){
    long long result = 1;
    while(n > 0){
        if(n & 1){
            result = result * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return result;
}

vector<long long> mat_mul(vector<long long>& arr, vector<long long>& brr, long long mod){
    vector<long long> result(9);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                result[i * 3 + j] += arr[i * 3 + k] * brr[k * 3 + j];
            }
            result[i * 3 + j] %= mod;
        }
    }
    return result;
}

vector<long long> pow(vector<long long>& a, long long n, long long mod){
    vector<long long> result(9);
    result[0] = 1; result[4] = 1; result[8] = 1;
    while(n > 0){
        if(n & 1){
            result = mat_mul(result, a, mod);
        }
        a = mat_mul(a, a, mod);
        n >>= 1;
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const long long p = 1e5 + 3;

    vector<long long> x(3 * p + 1);

    long long a, b, k;
    cin >> x[0] >> x[1] >> a >> b >> k;

    for(int i = 2; i <= 3 * p; i++){
        x[i] = (a * x[i - 1] + b * x[i - 2] + pow(i, k, p)) % p;
    }

    int q;
    cin >> q;

    while(q--){
        long long n;
        cin >> n;
        if(n <= 3 * p){
            cout << x[n] << "\n";
        }else{
            vector<long long> arr(9);
            arr[0] = a + 1;
            arr[1] = (b - a + p) % p;
            arr[2] = p - b;
            arr[3] = 1;
            arr[7] = 1;
            auto result = pow(arr, n / p - 2, p);
            long long answer = (result[0] * x[n % p + 2 * p])
                             + (result[1] * x[n % p + p])
                             + (result[2] * x[n % p]);
            cout << answer % p << "\n";
        }
    }

    return 0;
}