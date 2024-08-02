#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<pair<int, int>, bool> mp;

    int m;
    cin >> m;

    vector<pair<int, int>> arr(m);

    for(auto& a : arr){
        cin >> a.first >> a.second;
    }

    int n;
    cin >> n;

    vector<pair<int, int>> brr(n);

    for(auto& b : brr){
        cin >> b.first >> b.second;
        mp[b] = true;
    }

    for(int i = 0; i < n; i++){
        int dx = brr[i].first - arr[0].first;
        int dy = brr[i].second - arr[0].second;
        bool check = true;
        for(int i = 1; i < m; i++){
            int x = arr[i].first + dx;
            int y = arr[i].second + dy;
            if(mp.count(make_pair(x, y)) == 0){
                check = false;
                break;
            }
        }
        if(check){
            cout << dx << " " << dy;
            return 0;
        }
    }


    return 0;
}