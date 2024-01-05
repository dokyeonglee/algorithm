#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long ccw(pair<long long, long long>& a, pair<long long, long long>& b){
    return a.first * b.second - b.first * a.second;
}

bool compare(pair<long long, long long>& a, pair<long long, long long>& b){
    if((a > make_pair(0ll, 0ll)) ^ (b > make_pair(0ll, 0ll))){
        return a > b;
    }
    long long result = ccw(a, b);
    if(result == 0){
        return a.first * a.first + a.second * a.second < b.first * b.first + b.second * b.second;
    }
    return result > 0;
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<long long, long long>> arr(n + 1);
    
    for(auto& a : arr){
        cin >> a.first >> a.second;
    }

    for(int i = 0; i < n; i++){
        auto& a = arr[i];
        a.first -= arr.back().first;
        a.second -= arr.back().second;
    }

    sort(arr.begin(), arr.begin() + n, compare);

    for(int i = 0; i < n; i++){
        cout << arr[i].first + arr.back().first << " " << arr[i].second + arr.back().second << "\n";
    }

    return 0;
}