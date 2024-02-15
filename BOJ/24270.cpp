#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int sum = 0;

    for(int i = 0; i < n; i++){
        int s;
        cin >> s;
        sum += s;
    }

    int mod = 1e9 + 7;

    long long answer = 1;

    for(int i = k - sum + 1; i <= k - sum + n; i++){
        answer = answer * i % mod;
    }

    cout << answer;

    return 0;
}