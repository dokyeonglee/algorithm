#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int sum = 0;

    vector<int> cnt(k);
    
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        sum += x;
        sum %= k;
        cnt[sum]++;
    }

    int answer = 0;
    for(int i = 0; i < k; i++){
        answer = max(answer, cnt[i]);
    }

    cout << answer;

    return 0;
}