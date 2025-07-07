#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
using ll = long long;

ll count_total_pyramids(const vector<int>& blocks) {
    const int n = blocks.size();
    vector<int> max_height(n);

    max_height[0] = 1;
    for (int i = 1; i < n; ++i) {
        max_height[i] = min(max_height[i - 1] + 1, blocks[i]);
    }

    max_height[n - 1] = 1;
    for (int i = n - 2; i > 0; --i) {
        max_height[i] = min({max_height[i], max_height[i + 1] + 1, blocks[i]});
    }

    return accumulate(max_height.begin(), max_height.end(), 0ll);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> blocks(n);
    for (int& block : blocks) {
        cin >> block;
    }

    cout << count_total_pyramids(blocks);

    return 0;
}