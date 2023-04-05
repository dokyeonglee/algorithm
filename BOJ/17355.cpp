#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long pow(long long a, long long n, long long mod){
    if(n == 0){
        return 1;
    }
    long long result = pow(a, n / 2, mod);
    result = result * result % mod;
    if(n % 2 == 1){
        result = result * a % mod;
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> s(1e7 + 8);

    for(int i = 2; i * i <= 1e7; i++){
        if(s[i] == 0){
            for(int j = i * i; j <= 1e7; j += i){
                s[j] = i;
            }
        }
    }

    for(int i = 2; i <= 1e7 + 7; i++){
        if(s[i] == 0){
            s[i] = i;
        }
    }

    unordered_map<int, int> umap;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        a = b - a;
        int x = s[a];
        while(x != 0){
            umap[x]++;
            a /= x;
            if(a % x != 0){
                x = s[a];
            }
        }
        x = s[b];
        while(x != 0){
            umap[x]--;
            b /= x;
            if(b % x != 0){
                x = s[b];
            }
        }
    }

    pair<long long, long long> answer = make_pair(1, 1);
    int mod = 1e9 + 7;

    for(auto it : umap){
        if(it.second > 0){
            answer.first = answer.first * pow(it.first, it.second, mod) % mod;
        }else if(it.second < 0){
            answer.second = answer.second * pow(it.first, -it.second, mod) % mod;
        }
    }

    cout << answer.first << " " << answer.second;

    return 0;
}