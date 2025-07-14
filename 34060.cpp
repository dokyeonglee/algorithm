#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;

int find_parent(vector<int>& parent, int x){
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    if (x != y) {
        parent[y] = x;
    }
}

int count_min_pollution_areas(const vector<int>& y_coords) {
    const int n = y_coords.size() - 1;
    vector<int> parent(n + 1);
    iota(parent.begin(), parent.end(), 0);

    int x_coord = 1;
    unordered_map<int, unordered_map<int, int>> cell_index;
    cell_index[x_coord][y_coords[1]] = 1;

    for (int i = 2; i <= n; ++i) {
        if (y_coords[i] <= y_coords[i - 1]) {
            ++x_coord;
        } else if (y_coords[i] == y_coords[i - 1] + 1) {
            union_parent(parent, i, i - 1);
        }

        auto& left_column = cell_index[x_coord - 1];
        if (left_column.count(y_coords[i])) {
            union_parent(parent, i, left_column[y_coords[i]]);
        }

        cell_index[x_coord][y_coords[i]] = i;
    }

    int areas = 0;
    for (int i = 1; i <= n; ++i) {
        if (find_parent(parent, i) == i) {
            ++areas;
        }
    }

    return areas;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> y_coords(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> y_coords[i];
    }

    int min_pollution_areas = count_min_pollution_areas(y_coords);
    int max_pollution_areas = n;

    cout << min_pollution_areas << '\n';
    cout << max_pollution_areas << '\n';

    return 0;
}