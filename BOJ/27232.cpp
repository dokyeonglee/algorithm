#include <iostream>
#include <vector>
#include <set>

using namespace std;

int solve(set<pair<int, int>>& s, vector<pair<int, int>>& arr, int idx){

    int result = 0;

    auto it = s.lower_bound(arr[idx]);

    if(it == s.begin()){
        result += abs(it->second - next(it)->second);
    }else if(it == prev(s.end())){
        result += abs(prev(it)->second - arr[idx].second);
    }else{
        result -= abs(next(it)->second - prev(it)->second);
        result += abs(next(it)->second - arr[idx].second);
        result += abs(prev(it)->second - arr[idx].second);
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }

    if(k == 1){
        cout << 0;
        return 0;
    }

    set<pair<int, int>> s(arr.begin(), arr.begin() + k);

    long long result = 0;
    int temp = s.begin()->second;

    for(auto& i : s){
        result += abs(arr[temp].second - i.second);
        temp = i.second;
    }

    long long answer = result;

    for(int i = k; i < n; i++){

        result -= solve(s, arr, i - k);
        s.erase(arr[i - k]);
        
        s.insert(arr[i]);
        result += solve(s, arr, i);

        answer = min(answer, result);

    }
    

    cout << answer;

    return 0;
}