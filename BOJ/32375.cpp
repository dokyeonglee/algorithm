#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count_ge(const vector<int>& firecrackers, const int x) {
    return firecrackers.end() - lower_bound(firecrackers.begin(), firecrackers.end(), x);
}

int max_fireworks(vector<int>& firecrackers, const int k) {
    sort(firecrackers.begin(), firecrackers.end());

    int standalones = count_ge(firecrackers, k);
    int fireworks = standalones;

    int left = 0;
    int right = firecrackers.size() - standalones - 1;

    while (left < right) {
        if (firecrackers[left] + firecrackers[right] >= k) {
            ++fireworks;
            --right;
        }
        ++left;
    }

    if (fireworks == 0) {
        fireworks = -1;
    }

    return fireworks;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> firecrackers(n);
    for (int& a : firecrackers) {
        cin >> a;
    }

    cout << max_fireworks(firecrackers, k) << '\n';

    return 0;
}