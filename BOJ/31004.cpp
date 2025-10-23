#include <iostream>
#include <vector>

using namespace std;

int ask_query(const int left, const int right) {
    int result;
    cout << "? " << left << ' ' << right << endl;
    cin >> result;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;


    vector<bool> is_unique(n + 1);
    is_unique[1] = true;

    int unique_count = 1;
    int prev_cnt = 1;
    for (int i = 2; i <= n; ++i) {
        const int cnt = ask_query(1, i);
        if (cnt > prev_cnt) {
            ++unique_count;
            is_unique[i] = true;
        }
        prev_cnt = cnt;
    }

    prev_cnt = 1;
    for (int i = n - 1; i >= 1; --i) {
        const int cnt = ask_query(i, n);
        if (cnt <= prev_cnt && is_unique[i]) {
            --unique_count;
            is_unique[i] = false;
        }
        prev_cnt = cnt;
    }

    cout << "! " << unique_count << ' ';
    for (int i = 1; i <= n; ++i) {
        if (is_unique[i]) {
            cout << i << ' ';
        }
    }
    cout << endl;

    return 0;
}