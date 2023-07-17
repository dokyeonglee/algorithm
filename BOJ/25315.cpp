#include <iostream>
#include <vector>

using namespace std;

int ccw(pair<int, int>& a, pair<int, int>& b, pair<int, int>& c){
    long long result = 1ll * (b.first - a.first) * (c.second - a.second) - 1ll * (b.second - a.second) * (c.first - a.first);
    if(result < 0){
        return -1;
    }else if(result == 0){
        return 0;
    }else{
        return 1;
    }
}

bool is_intersect(vector<pair<int, int>>& s, vector<pair<int, int>>& e, int x, int y){
    int temp = ccw(s[x], e[x], s[y]) * ccw(s[x], e[x], e[y]);
    int temp2 = ccw(s[y], e[y], s[x]) * ccw(s[y], e[y], e[x]);
    return temp < 0 and temp2 < 0;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> s(n + 1);
    vector<pair<int, int>> e(n + 1);
    vector<int> w(n + 1);

    long long answer = 0;

    for(int i = 0; i < n; i++){
        cin >> s[i].first >> s[i].second >> e[i].first >> e[i].second >> w[i];
        answer += w[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(is_intersect(s, e, i, j)){
                answer += min(w[i], w[j]);
            }
        }
    }

    cout << answer;

    return 0;
}