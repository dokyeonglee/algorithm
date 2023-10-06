#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    vector<int> cnt(20);

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        for(int j = 0; j < 20; j++){
            if(x & (1 << j)){
                cnt[j]++;
            }
        }
    }

    long long answer = 0;

    for(int i = 0; i < 20; i++){
        answer += (n - cnt[i]) * cnt[i] * (1ll << i);
    }

    cout << answer;

    return 0;
}