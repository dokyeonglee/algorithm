#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> lumi;
    lumi.reserve(1 << 17);

    for (int i = 1; i < 10; ++i) {
        lumi.push_back(i);
    }
    for (int i = 10; i < 100000; i *= 10) {
        for (int j = i / 10; j < i; ++j) {
            lumi.push_back(j * i + j);
        }
        for (int j = i / 10; j < i; ++j) {
            for (int k = 0; k < 10; ++k) {
                lumi.push_back((j * 10 + k) * i + j);
            }
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int answer = 0;
        int left = 0;
        int right = lumi.size() - 1;
        while (left <= right) {
            int sum = lumi[left] + lumi[right];
            if (sum == n) {
                answer += 2;
                if (left == right) {
                    --answer;
                }
                ++left;
                --right;
            } else if (sum < n) {
                ++left;
            } else {
                --right;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}