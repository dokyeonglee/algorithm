#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void flip(vector<int>& pancakes, const int k) {
    reverse(pancakes.begin(), pancakes.begin() + k);
    for (int i = 0; i < k; ++i) {
        pancakes[i] = -pancakes[i];
    }
}

int find_largest_pancake(const vector<int>& pancakes, const int j) {
    int largest_pancake = 0;
    for (int i = 0; i < j; ++i) {
        if (abs(pancakes[i]) > abs(pancakes[largest_pancake])) {
            largest_pancake = i;
        }
    }
    return ++largest_pancake;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> pancakes(n);
        for (int& cake : pancakes) {
            cin >> cake;
        }

        vector<int> answer;

        for (int j = n; j > 1; --j) {
            const int largest_pancake = find_largest_pancake(pancakes, j);

            if (largest_pancake == j && pancakes[largest_pancake - 1] > 0) {
                continue;
            }

            answer.push_back(largest_pancake);
            flip(pancakes, largest_pancake);

            if (pancakes[0] > 0) {
                answer.push_back(1);
                pancakes[0] = -pancakes[0];
            }

            answer.push_back(j);
            flip(pancakes, j);
        }

        if (pancakes[0] < 0) {
            answer.push_back(1);
        }

        cout << answer.size() << ' ';
        for (const int x : answer) {
            cout << x << ' ';
        }
        cout << '\n';
    }


    return 0;
}