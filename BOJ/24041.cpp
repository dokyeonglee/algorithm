#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, g, k;
    cin >> n >> g >> k;

    vector<vector<pair<int, int>>> arr(2);
    for(int i = 0; i < n; i++){
        int s, l, o;
        cin >> s >> l >> o;
        arr[o].push_back(make_pair(s, l));
    }

    long long left = 0;
    long long right = 2e9;

    long long answer = 0;

    vector<long long> v(arr[1].size());

    while(left <= right){
        long long mid = (left + right) / 2;
        long long sum = 0;
        for(int i = 0; i < arr[0].size(); i++){
            sum += arr[0][i].first * max(1ll, mid - arr[0][i].second);
        }
        if(sum > g){
            right = mid - 1;
            continue;
        }
        for(int i = 0; i < arr[1].size(); i++){
            v[i] = arr[1][i].first * max(1ll, mid - arr[1][i].second);
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < (int)arr[1].size() - k; i++){
            sum += v[i];
        }
        if(sum <= g){
            answer = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    cout << answer;

    return 0;
}