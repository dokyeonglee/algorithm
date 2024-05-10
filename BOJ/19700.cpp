#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for(auto& a : arr){
        cin >> a.first >> a.second;
    }

    sort(arr.begin(), arr.end(), greater<>());

    multiset<int> team;

    for(int i = 0; i < n; i++){
        auto it = team.lower_bound(arr[i].second);
        if(it == team.begin()){
            team.insert(1);
        }else{
            it--;
            int temp = *it;
            team.erase(it);
            team.insert(temp + 1);
        }
    }

    cout << team.size();

    return 0;
}