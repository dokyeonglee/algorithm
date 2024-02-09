#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<long long> arr(n);
        for(auto& a : arr){
            cin >> a;
            a = -a;
        }

        priority_queue<long long> pq(arr.begin(), arr.end());

        long long answer = 1;
        int mod = 1e9 + 7;

        while(pq.size() > 1){
            long long a = pq.top(); pq.pop();
            long long b = pq.top(); pq.pop();
            long long c = a * b;
            answer *= (a % mod) * (b % mod) % mod;
            answer %= mod;
            pq.push(-c);
        }

        cout << answer % mod << "\n";

    }

    return 0;
}