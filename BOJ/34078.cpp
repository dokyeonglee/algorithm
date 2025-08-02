#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count_cycles(const vector<int>& heights) {
    const int n = heights.size();
    vector<bool> visited(n);
    int cycle_count = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            int now = i;
            while (!visited[now]) {
                visited[now] = true;
                now = heights[now];
            }

            ++cycle_count;
        }
    }

    return cycle_count;
}

int calculate_min_swaps(const vector<int>& heights) {
    const int n = heights.size();

    int swaps_to_ascending = n - count_cycles(heights);

    const vector<int> reversed_heights(heights.rbegin(), heights.rend());
    int swaps_to_descending = n - count_cycles(reversed_heights);

    return min(swaps_to_ascending, swaps_to_descending);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> heights(n);
    for (int& h : heights) {
        cin >> h;
        --h;
    }

    int max_ungna = n - 2;
    int min_swaps = calculate_min_swaps(heights);

    cout << max_ungna << ' ' << min_swaps << '\n';

    return 0;
}