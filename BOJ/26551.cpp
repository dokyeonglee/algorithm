#include <iostream>
#include <vector>
#include <map>

using namespace std;

int find_parent(vector<int>& parent, int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, int x, int y) {
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    if (x != y) {
        parent[y] = x;
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> parent{0};
    map<string, int> name_to_id;

    int id_count = 0;

    while (n--) {
        string name1, relation, name2;
        cin >> name1 >> relation >> name2;

        if (name_to_id.count(name1) == 0) {
            name_to_id[name1] = ++id_count;
            parent.emplace_back(id_count);
        }

        if (name_to_id.count(name2) == 0) {
            name_to_id[name2] = ++id_count;
            parent.emplace_back(id_count);
        }

        union_parent(parent, name_to_id[name1], name_to_id[name2]);
    }

    int m;
    cin >> m;

    while (m--) {
        string name1, name2;
        cin >> name1 >> name2;

        if (find_parent(parent, name_to_id[name1]) == find_parent(parent, name_to_id[name2])) {
            cout << "Related\n";
        } else {
            cout << "Not Related\n";
        }
    }

    return 0;
}