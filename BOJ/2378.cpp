#include <iostream>
#include <vector>
#include <map>

using namespace std;

void update(map<int, int>& cnt, int x, int delta) {
    for (int i = 2; i * i <= x; ++i) {
        while (x % i == 0) {
            cnt[i] += delta;
            x /= i;
        }
    }
    if (x > 1) {
        cnt[x] += delta;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    --n;

    map<int, int> cnt;
    map<int, int> cnt2;

    update(cnt2, m, 1);

    if (cnt2.rbegin()->first > n) {
        cout << 0;
        return 0;
    }

    int sz = n / 2;

    vector<int> answer;
    for (int i = 1; i <= sz; ++i) {
        if ((n - i + 1) % i == 0) {
            update(cnt, (n - i + 1) / i, 1);
        } else {
            update(cnt, n - i + 1, 1);
            update(cnt, i, -1);
        }

        bool check = true;
        for (auto& p : cnt2) {
            if (cnt[p.first] < p.second) {
                check = false;
                break;
            }
        }
        if (check) {
            answer.push_back(i + 1);
        }
    }

    sz = answer.size() * 2;
    if (sz > 0 && n - answer.back() + 2 == answer.back()) {
        --sz;
    }

    cout << sz << '\n';
    for (const int a : answer) {
        cout << a << ' ';
    }
    for (int i = sz / 2 - 1; i >= 0; --i) {
        cout << n - answer[i] + 2 << ' ';
    }

    return 0;
}