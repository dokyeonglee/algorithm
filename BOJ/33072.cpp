#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> c(n);
    vector<int> p(n);

    for(int i = 0; i < n; i++){
        cin >> c[i];
    }

    for(int i = 0; i < n; i++){
        cin >> p[i];
    }

    long long a, b;
    cin >> a >> b;

    vector<long long> dp(250001);

    for(int i = 0; i < n; i++){
        long long temp = p[i] * b - a * c[i];
        if(temp <= 0){
            continue;
        }
        for(int j = 250000; j >= p[i]; j--){
            dp[j] = max(dp[j], dp[j - p[i]] + temp);
        }
    }

    int q;
    cin >> q;

    while(q--){
        int C, P;
        cin >> C >> P;
        if(P * b >= a * C){
            cout << "0\n";
            continue;
        }
        int answer = lower_bound(dp.begin(), dp.end(), a * C - P * b) - dp.begin();
        if(answer == 250001){
            answer = -1;
        }
        cout << answer << "\n";
    }

    return 0;

}