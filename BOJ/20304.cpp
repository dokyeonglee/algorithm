#include <iostream>
#include <queue>

using namespace std;

int calculate_max_safety(const vector<int>& passwords, int n) {
    vector<bool> visited(n + 1);
    queue<pair<int, int>> q;

    for (const int password : passwords) {
        visited[password] = true;
        q.emplace(password, 0);
    }

    int max_safety = 0;

    while (!q.empty()) {
        int now = q.front().first;
        max_safety = q.front().second;
        q.pop();

        for (int bit = 1; bit <= n; bit <<= 1) {
            int next = (now ^ bit);
            if (next <= n && !visited[next]) {
                visited[next] = true;
                q.emplace(next, max_safety + 1);
            }
        }

    }
    
    return max_safety;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<int> passwords(m);
    for (int& password : passwords) {
        cin >> password;
    }

    cout << calculate_max_safety(passwords, n) << '\n';

    return 0;
}