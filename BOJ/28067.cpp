#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int cnt = (n + 1) * (m + 1);

    set<pair<int, pair<int, int>>> answer;

    pair<int, int> a = make_pair(0, 0);

    for(int i = 0; i < cnt; i++){
        pair<int, int> b = make_pair(i / (m + 1), i % (m + 1));
        for(int j = i + 1; j < cnt; j++){
            pair<int, int> c = make_pair(j / (m + 1), j % (m + 1));
            if((a.first - b.first) * (b.second - c.second) ==  (b.first - c.first) * (a.second - b.second)){
                continue;
            }
            int dist = (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
            int dist2 = (c.first - b.first) * (c.first - b.first) + (c.second - b.second) * (c.second - b.second);
            int dist3 = (a.first - c.first) * (a.first - c.first) + (a.second - c.second) * (a.second - c.second);
            if(dist > dist3){
                swap(dist, dist3);
            }
            if(dist2 > dist3){
                swap(dist2, dist3);
            }
            if(dist > dist2){
                swap(dist, dist2);
            }
            answer.insert(make_pair(dist, make_pair(dist2, dist3)));
        }
    }

    cout << answer.size();

    return 0;
}