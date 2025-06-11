#include <iostream>
#include <vector>
#include <numeric>

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

int count_component(vector<int>& parent) {
    int component_count = 0;
    for (int i = 0; i < parent.size(); ++i) {
        if (find_parent(parent, i) == i) {
            ++component_count;
        }
    }
    return component_count;
}

bool has_isolated_vertex(const vector<string>& roads) {
    for (auto& road : roads) {
        if (road.find('Y') == string::npos) {
            return true;
        }
    }
    return false;
}

//int connect_components

int min_edits_to_connect(const vector<string>& roads) {

    const int n = roads.size();

    if (n == 1) {
        return 0;
    }

    if (has_isolated_vertex(roads)) {
        return -1;
    }

    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0);

    int extra_edges = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (roads[i][j] == 'Y') {
                if (find_parent(parent, i) != find_parent(parent, j)) {
                    union_parent(parent, i, j);
                } else {
                    ++extra_edges;
                }
            }
        }
    }

    int component_count = count_component(parent);
    if (component_count - 1 <= extra_edges) {
        return component_count - 1;
    }

    return -1;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> roads(n);
    for (auto& road : roads) {
        cin >> road;
    }

    cout << min_edits_to_connect(roads);

    return 0;
}