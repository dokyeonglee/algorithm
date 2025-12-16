#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    vector<int> prime{2};
    for (int i = 3; i <= n; i += 2) {
        if (is_prime[i]) {
            prime.push_back(i);
        }
    }

    int left = 0;
    int right = prime.size() - 1;
    int answer = -1;

    while (left <= right) {
        int mid = (left + right) / 2;
        cout << "? " << prime[mid] << endl;

        int x;
        cin >> x;

        if (x == 0) {
            answer = prime[mid];
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << "! " << answer << endl;

    return 0;
}