#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX_REPEAT = 1000000000;
constexpr int MAX_LOG = 32 - __builtin_clz(MAX_REPEAT);

int find_end_port(const vector<vector<int>>& sparse_table, const int start, int repeat_count) {
    int end_port = start;

    for (int i = MAX_LOG - 1; i >= 0; --i) {
        if (repeat_count & (1 << i)) {
            end_port = sparse_table[i][end_port];
        }
    }

    return end_port;
}

vector<vector<int>> build_sparse_table(const vector<vector<int>>& adj, const vector<int>& dir) {
    const int n = adj.size() - 1;
    vector<vector<int>> sparse_table(MAX_LOG, vector<int>(n + 1));

    for (int i = 1; i <= n; ++i) {
        int j = i;
        for (const int d : dir) {
            j = adj[j][d];
        }
        sparse_table[0][i] = j;
    }

    for (int k = 1; k < MAX_LOG; ++k) {
        for (int i = 1; i <= n; ++i) {
            sparse_table[k][i] = sparse_table[k - 1][sparse_table[k - 1][i]];
        }
    }

    return sparse_table;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, repeat_count;
    cin >> n >> m >> repeat_count;

    vector<vector<int>> adj(n + 1, vector<int>(2));
    for (int i = 1; i <= n; ++i) {
        cin >> adj[i][0] >> adj[i][1];
    }

    vector<int> dir(m);
    for (int& d : dir) {
        char c;
        cin >> c;

        d = (c == 'R');
    }

    auto sparse_table = build_sparse_table(adj, dir);
    int end_port = find_end_port(sparse_table, 1, repeat_count);

    cout << end_port << '\n';

    return 0;
}