#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<pair<int, int>> pq;

    int n;
    cin >> n;

    int t, d;

    while(n--){
        cin >> t >> d;
        pq.emplace(-d, -t);
    }

    int m;
    cin >> m;

    vector<pair<int, pair<int, int>>> add(m);

    int w;

    for(int i = 0; i < m; i++){
        cin >> w >> t >> d;
        add[i] = make_pair(w, make_pair(-d, -t));
    }

    sort(add.begin(), add.end());

    long long now = 0;

    for(int i = 0; i < m; i++){
        w = add[i].first;
        while(!pq.empty()){
            d = -pq.top().first;
            t = -pq.top().second; 
            pq.pop();
            if(now + t > d){
                cout << "NO";
                return 0;
            }
            if(now + t <= w){
                now += t;
            }else{
                pq.emplace(-d, -(t - (w - now)));
                break;
            }
        }
        now = w;
        pq.push(add[i].second);
    }

    while(!pq.empty()){
        d = -pq.top().first;
        t = -pq.top().second;
        pq.pop();
        if(now + t > d){
            cout << "NO";
            return 0;
        }
        now += t;
    }

    cout << "YES\n";
    cout << now;

    return 0;
}