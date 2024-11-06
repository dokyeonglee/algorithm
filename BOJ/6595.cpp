#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int find_parent(vector<int>& parent, int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    parent[y] = x;
}

double distance_square(pair<int, int>& a, pair<int, int>& b){
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int scenario_num = 0;

    cout << fixed;
    cout.precision(3);

    while(1){

        int n;
        cin >> n;

        if(n == 0){
            break;
        }

        scenario_num++;

        vector<pair<int, int>> arr(n);

        for(auto& a : arr){
            cin >> a.first >> a.second;
        }

        vector<pair<int, pair<int, int>>> edges;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                edges.emplace_back(distance_square(arr[i], arr[j]), make_pair(i, j));
            }
        }

        sort(edges.begin(), edges.end());

        double answer = -1;

        vector<int> parent(n + 1);

        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }

        for(auto& edge : edges){

            int c = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            if(find_parent(parent, u) != find_parent(parent, v)){
                union_parent(parent, u, v);
                if(find_parent(parent, 0) == find_parent(parent, 1)){
                    answer = sqrtl(c);
                    break;
                }
            }

        }

        cout << "Scenario #" << scenario_num << "\n";
        cout << "Frog Distance = " << answer << "\n\n";

    }


    return 0;
}