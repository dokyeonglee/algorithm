#include <iostream>
#include <queue>

using namespace std;

int mst(const vector<string>& words) {
    vector<bool> visited(words.size());

    priority_queue<pair<int, int>> pq;
    pq.emplace(0, 0);

    int result = 0;
    int cnt = 0;

    while (!pq.empty()) {
        const auto [cost, now] = pq.top();
        pq.pop();

        if (visited[now]) {
            continue;
        }
        
        visited[now] = true;
        result = max(result, -cost);
        if (++cnt == words.size()) {
            break;
        }

        for (int next = 0; next < words.size(); ++next) {
            if (!visited[next]) {
                int w = 0;
                for (int j = 0; j < words[next].size(); ++j) {
                    w += abs(words[now][j] - words[next][j]);
                }
                pq.emplace(-w, next);
            }
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<string> words(n);
    for (auto& word : words) {
        cin >> word;
    }

    cout << mst(words) << '\n';

    return 0;
}