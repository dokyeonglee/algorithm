#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<int, int> build_code_to_index_map(const vector<int>& codes) {
    const int n = codes.size() - 1;
    unordered_map<int, int> code_to_index;

    for (int i = 1; i <= n; ++i) {
        code_to_index[codes[i]] = i;
    }

    return code_to_index;
}

vector<int> build_predecessors(const vector<int>& codes, const unordered_map<int, int>& code_to_index, const int k) {
    const int n = codes.size() - 1;
    vector<int> predecessors(n + 1, -1);

    vector<bool> visited(n + 1);
    visited[1] = true;

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < k; ++i) {
            auto it = code_to_index.find(codes[now] ^ (1 << i));
            if (it == code_to_index.end()) {
                continue;
            }

            int next = it->second;
            if (!visited[next]) {
                visited[next] = true;
                predecessors[next] = now;
                q.push(next);
            }
        }

    }

    return predecessors;
}

string build_path(const vector<int>& predecessors, int dst) {
    if (predecessors[dst] == -1) {
        return "-1";
    }

    vector<int> reversed_path;
    int now = dst;

    while (now != 1) {
        reversed_path.push_back(now);
        now = predecessors[now];
    }
    reversed_path.push_back(1);

    string path;
    for (int i = reversed_path.size() - 1; i >= 0; --i) {
        path += to_string(reversed_path[i]) + ' ';
    }

    return path;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> codes(n + 1);
    for (int i = 1; i <= n; ++i) {
        string str;
        cin >> str;
        codes[i] = stoi(str, nullptr, 2);
    }
    
    auto code_to_index = build_code_to_index_map(codes);
    auto predecessors = build_predecessors(codes, code_to_index, k);

    int m;
    cin >> m;

    while (m--) {
        int dst;
        cin >> dst;
        cout << build_path(predecessors, dst) << '\n';
    }

    return 0;
}