#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    map<long long, long long> cnt;

    long long answer = 0;

    for(int i = 0; i < n; i++){
        long long u, v;
        cin >> u >> v;
        answer += cnt[v - k * u]++;
    }

    answer <<= 1;

    cout << answer;

    return 0;
}