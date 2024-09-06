#include <iostream>
#include <vector>

using namespace std;

int dfs(pair<int, int>& base_station, vector<pair<int, int>>& nodes, vector<int>& selected, int idx, int depth){

    if(nodes.size() - idx < selected.size() - depth){
        return 0;
    }

    if(depth == selected.size()){

        int p = 0;
        int u = 0;
        int min_r = 1e9;
        int max_r = -1;
        int min_c = 1e9;
        int max_c = -1;

        for(auto& s : selected){
            p += abs(base_station.first - nodes[s].first) + abs(base_station.second - nodes[s].second);
            min_r = min(min_r, nodes[s].first);
            max_r = max(max_r, nodes[s].first);
            min_c = min(min_c, nodes[s].second);
            max_c = max(max_c, nodes[s].second);
        }

        u = (max_r - min_r + 1) * (max_c - min_c + 1);

        return max(0, p - u);
    }

    int result = 0;

    for(int i = idx; i < nodes.size(); i++){
        selected[depth] = i;
        result = max(result, dfs(base_station, nodes, selected, i + 1, depth + 1));
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k1, k2;
    cin >> n >> m >> k1 >> k2;

    pair<int, int> base_station;
    vector<pair<int, int>> nodes;

    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < n; j++){
            if(str[j] == 'B'){
                base_station = make_pair(i, j);
            }else if(str[j] == 'N'){
                nodes.emplace_back(i, j);
            }
        }
    }

    vector<int> selected(k1);

    int answer1 = (k1 ? dfs(base_station, nodes, selected, 0, 0) : 0);

    cout << answer1 << "\n";

    if(k1 == k2){
        cout << answer1;
        return 0;
    }

    selected.resize(k2);

    cout << (k2 ? dfs(base_station, nodes, selected, 0, 0) : 0);

    return 0;
}