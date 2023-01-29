#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, pair<long long, long long>>& a, pair<int, pair<long long, long long>>& b){
    return a.second.first * b.second.second > b.second.first * a.second.second;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<long long> arr(4);
    for(int i = 0; i < 4; i++){
        cin >> arr[i];
    }

    vector<vector<int>> v(4);
    for(int i = 0; i < n; i++){
        char c;
        int x;
        cin >> c >> x;
        v[c - 'A'].push_back(x);
    }

    for(int i = 0; i < 4; i++){
        sort(v[i].begin(), v[i].end(), greater<>());
    }

    vector<int> idx(4);

    vector<pair<int, pair<long long, long long>>> vv;
    for(int i = 0; i < 4; i++){
        long long sum = arr[i];
        for(int j = 0; j < v[i].size(); j++){
            vv.push_back(make_pair(i, make_pair(v[i][j], sum)));
            sum += v[i][j];
        }
    }

    sort(vv.begin(), vv.end(), compare);

    for(int i = 0; i < k; i++){
        cout << char('A' + vv[i].first) << " " << vv[i].second.first << "\n";
    }

    return 0;
}