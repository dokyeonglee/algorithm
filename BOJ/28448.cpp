#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l;
    cin >> n >> l;

    vector<pair<int, int>> arr;

    long long answer = 0;

    for(int i = 0; i < n; i++){
        int k, t;
        cin >> k >> t;
        if(t <= 5){
            answer += t;
        }else{
            arr.push_back(make_pair(k, t));
        }
    }

    sort(arr.begin(), arr.end(), greater<>());

    int now = 0;

    for(int i = 0; i < arr.size(); i++){
        long long result = (long long)arr[i].first * arr[i].second;
        if(l - now < result){
            answer += result - (l - now);
            now -= result - (l - now);
        }
        now += result - 5 * arr[i].first;
        answer += arr[i].second;
    }

    cout << answer;

    return 0;
}