#include <iostream>
#include <vector>

using namespace std;

constexpr int GIVE = 1;
constexpr int TAKE = 2;
constexpr int GIVE_AND_TAKE = (GIVE | TAKE);

int count_candidates(const vector<int>& status, const int m, const int sejong) {
    if (status[sejong] & TAKE) {
        return 1;
    }

    const int n = status.size() - 1;
    bool is_sejong_manito = (status[sejong] & GIVE) != 0;
    int candidates = n - 1 - m + is_sejong_manito;

    if (candidates != 2) {
        return candidates;
    }

    if (is_sejong_manito) {
        for (int i = 1; i <= n; ++i) {
            if ((status[i] & GIVE_AND_TAKE) == 0) {
                return 1;
            }
        }
    }

    return 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> status(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        status[a] |= TAKE;
        status[b] |= GIVE;
    }

    int sejong;
    cin >> sejong;

    int candidates = count_candidates(status, m, sejong);

    if (candidates == 1) {
        cout << "NOJAM\n";
    } else {
        cout << candidates << '\n';
    }

    return 0;
}