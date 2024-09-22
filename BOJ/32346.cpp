#include <iostream>
#include <vector>

using namespace std;

long long pow(long long a, long long n, long long mod){
    long long result = 1;
    while(n){
        if(n % 2){
            result = a * result % mod;
        }
        a = a * a % mod;
        n /= 2;
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    const int mod = 1e9 + 7;

    vector<long long> fac(2001);
    fac[0] = 1;

    for(int i = 1; i <= 2000; i++){
        fac[i] = i * fac[i - 1] % mod;
    }

    vector<long long> fac_inv(2001);
    fac_inv[2000] = pow(fac[2000], mod - 2, mod);

    for(int i = 2000; i > 0; i--){
        fac_inv[i - 1] = i * fac_inv[i] % mod;
    }


    int n;
    cin >> n;

    string str;
    cin >> str;

    int idx = 0;

    while(idx < n and str[idx] == '<'){
        idx++;
    }

    int answer = 0;

    vector<pair<int, int>> v;

    while(idx < n){
        int temp = idx;
        while(temp < n and str[temp] == '>'){
            temp++;
        }
        int temp2 = temp;
        while(temp2 < n and str[temp2] == '<'){
            temp2++;
        }
        int l = temp - idx;
        int r = temp2 - temp;
        int diff = abs(l - r);
        if(l and r){
            if(l > r){
                v.emplace_back(idx + diff, temp2 - 1);
            }else{
                v.emplace_back(idx, temp2 - 1 - diff);
            }
        }
        idx = temp2;
    }

    for(auto& p : v){
        while(p.first < p.second){
            answer = (answer + fac[p.first + n - 1 - p.second] * fac_inv[p.first] % mod * fac_inv[n - 1 - p.second]) % mod;
            p.first++;
            p.second--;
        }
    }

    cout << answer;

    return 0;
}