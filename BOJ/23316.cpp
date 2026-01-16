#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long total = 0;
    long long total_of_square = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];

        total += b[i];
        total_of_square += 1ll * b[i] * b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int j = 0;
    long long sum = 0;
    long long sum_of_square = 0;

    double answer = 0;

    for (int i = 0; i < n; ++i) {
        while (j < n && a[i] >= b[j]) {
            sum_of_square += 1ll * b[j] * b[j];
            sum += b[j++];
        }
        answer += (2ll * j - n) * a[i] * a[i] - (2ll * sum - total) * 2 * a[i] 
                + 2 * sum_of_square - total_of_square;
    }

    answer /= 1.0 * n;

    cout << fixed;
    cout.precision(10);
    cout << answer;

    return 0;
}