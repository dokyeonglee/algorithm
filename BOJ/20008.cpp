#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<pair<int, int>>& arr, vector<int>& usable_time, int t, int hp){
    if(hp <= 0){
        return t;
    }
    int result = 1e9;
    bool check = false;
    for(int i = 0; i < arr.size(); i++){
        if(usable_time[i] <= t){
            auto temp = usable_time[i];
            usable_time[i] = t + arr[i].first;
            result = min(result, dfs(arr, usable_time, t + 1, hp - arr[i].second));
            usable_time[i] = temp;
            check = true;
        }
    }
    if(!check){
        result = min(result, dfs(arr, usable_time, t + 1, hp));
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, hp;
    cin >> n >> hp;

    vector<pair<int, int>> arr(n);
    for(auto& a : arr){
        cin >> a.first >> a.second;
    }

    vector<int> usable_time(n);

    cout << dfs(arr, usable_time, 0, hp);

    return 0;

}