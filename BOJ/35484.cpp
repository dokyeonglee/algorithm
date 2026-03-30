#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int left = 0;
    int right = n / 2;
    int answer = n;
    int cnt;

    string str = "? 0 " + to_string(n);

    while (left <= right) {
        int mid = (left + right) / 2;

        cout << str << ' ' << mid << endl;
        cin >> cnt;

        if (cnt) {
            answer = 2 * mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if (answer != n) {
        cout << "? 1 " << n << ' ' << answer / 2 - 1 << endl;
        cin >> cnt;

        if (cnt) {
            --answer;
        }
    }

    cout << "! " << answer << endl;

    return 0;
}