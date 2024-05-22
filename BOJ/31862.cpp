#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> points(n + 1);
    vector<pair<int, int>> yet;

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(c == 0){
            yet.emplace_back(a, b);
        }else if(c == 1){
            points[a]++;
        }else{
            points[b]++;
        }
    }

    int sz = yet.size();

    int answer = 0;

    vector<int> cnt(1e5 + 1);

    int max_point = 0;

    for(int i = 1; i <= n; i++){
        max_point = max(max_point, points[i]);
        cnt[points[i]]++;
    }

    for(int i = 0; i < (1 << sz); i++){

        int temp = max_point;

        for(int j = 0; j < sz; j++){
            if(i & (1 << j)){
                cnt[points[yet[j].first]]--;
                cnt[++points[yet[j].first]]++;
                temp = max(temp, points[yet[j].first]);
            }else{
                cnt[points[yet[j].second]]--;
                cnt[++points[yet[j].second]]++;
                temp = max(temp, points[yet[j].second]);
            }
        }

        if(temp == points[k] and cnt[points[k]] == 1){
            answer++;
        }

        for(int j = 0; j < sz; j++){
            if(i & (1 << j)){
                cnt[points[yet[j].first]]--;
                cnt[--points[yet[j].first]]++;
            }else{
                cnt[points[yet[j].second]]--;
                cnt[--points[yet[j].second]]++;
            }
        }

    }

    cout << answer;

    return 0;
}