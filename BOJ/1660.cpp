#include <iostream>
#include <vector>

using namespace std;

constexpr int INF = 1e9;

vector<int> generate_tetrahedrons(const int n) {
    vector<int> tetrahedrons;

    int tetrahedron_sum = 0;
    for (int layer = 1; ; ++layer) {
        tetrahedron_sum += layer * (layer + 1) / 2;
        if (tetrahedron_sum > n) break;
        tetrahedrons.push_back(tetrahedron_sum);
    }

    return tetrahedrons;
}

int min_tetrahedrons_count(const vector<int>& tetrahedrons, const int n) {
    vector<int> dp(n + 1, INF);
    dp[0] = 0;

    for (const int tetrahedron : tetrahedrons) {
        for (int j = tetrahedron; j <= n; ++j) {
            dp[j] = min(dp[j], dp[j - tetrahedron] + 1);
        }
    }

    return dp[n];
}

int main(){
    int n;
    cin >> n;

    auto tetrahedrons = generate_tetrahedrons(n);
    cout << min_tetrahedrons_count(tetrahedrons, n) << '\n';

    return 0;
}