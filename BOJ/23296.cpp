#include <iostream>
#include <vector>

using namespace std;

void traverse_chain(const vector<int>& destination, vector<bool>& visited, const int start, vector<int>& order) {
    int now = start;
    while (!visited[now]) {
        visited[now] = true;
        order.push_back(now);
        now = destination[now];
    }
    order.push_back(now);
}

vector<int> decide_button_order(const vector<int>& destination) {
    const int n = destination.size() - 1;
    vector<int> in_degree(n + 1);
    vector<bool> visited(n + 1);

    for (int i = 1; i <= n; ++i) {
        ++in_degree[destination[i]];
    }

    vector<int> order;

    visited[1] = true;
    traverse_chain(destination, visited, destination[1], order);

    for (int i = 2; i <= n; ++i) {
        if (in_degree[i] == 0) {
            traverse_chain(destination, visited, i, order);
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (!visited[i]) {
            traverse_chain(destination, visited, i, order);
        }
    }

    return order;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> destination(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> destination[i];
    }

    auto button_order = decide_button_order(destination);

    cout << button_order.size() << '\n';
    for (int i = 0; i < button_order.size(); ++i) {
        cout << button_order[i] << ' ';
    }

    return 0;
}