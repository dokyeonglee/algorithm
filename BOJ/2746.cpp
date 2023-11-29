#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    vector<int> cnt(1e6 + 1);
    long long sum = 0;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        cnt[arr[i]]++;
        sum += arr[i];
    }

    sort(arr.begin(), arr.end());

    sum -= arr[n];

    cnt[arr[n]]--;
    cnt[arr[n - 1]]--;

    long long answer = 0;

    if(sum - 2 * arr[n - 1] <= 1e6){
        answer += cnt[sum - 2 * arr[n - 1]];
    }

    cnt[arr[n - 1]]++;

    for(int i = 1; i < n - 1; i++){
        cnt[arr[i]]--;
        long long x = sum - arr[i] - arr[n];
        if(x > 1e6 or x < 0){
            continue;
        }
        answer += cnt[x];
    }

    if(sum - arr[n - 1] == 2 * arr[n - 2]){
        answer++;
    }

    cout << answer;

    return 0;
}