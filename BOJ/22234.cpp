#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, T, w;
    cin >> n >> T >> w;

    queue<pair<int, int>> q;

    while(n--){
        int p, t;
        cin >> p >> t;
        q.emplace(p, t);
    }

    int m;
    cin >> m;

    vector<pair<int, pair<int, int>>> arr(m);
    for(auto& a : arr){
        cin >> a.second.first >> a.second.second >> a.first;
    }

    sort(arr.rbegin(), arr.rend());

    int now = 0;

    while(w > 0){
        auto customer = q.front();
        q.pop();
        int cnt = min(w, min(T, customer.second));
        for(int i = 0; i < cnt; i++){
            cout << customer.first << "\n";
        }
        customer.second -= cnt;
        w -= cnt;
        now += cnt;
        while(!arr.empty() and arr.back().first <= now){
            auto p = arr.back().second;
            q.emplace(p);
            arr.pop_back();
        }
        if(customer.second > 0){
            q.emplace(customer);
        }
    }

    return 0;

}