#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<long long, pair<int, int>> mp;

    int n;
    cin >> n;

    vector<long long> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        if(mp.count(arr[i])){
            mp[arr[i]].second = i;
        }else{
            mp[arr[i]] = make_pair(i, i);
        }
        arr[i] += arr[i - 1];
    }

    long long max_sum = 0;
    int cnt = 0;

    for(auto& it : mp){
        long long sum = arr[it.second.second] - arr[it.second.first - 1];
        if(max_sum < sum){
            max_sum = sum;
            cnt = 1;
        }else if(max_sum == sum){
            cnt++;
        }
    }

    cout << max_sum << " " << cnt;

    return 0;
}