#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    unordered_map<long long, long long> cnt;

    for(int i = 0; i < n; i++){
        
        int a, b, c;
        cin >> a >> b >> c;

        int g = gcd(a, b);

        a /= g;
        b /= g;

        cnt[a * 1e9 + b]++;

    }

    long long answer = 0;

    for(auto& it : cnt){
        answer += (n - it.second) * it.second;
    }

    answer /= 2;

    cout << answer;

    return 0;
}