#include <iostream>
#include <vector>

using namespace std;

constexpr int INITIAL_MIN_TEMP = 0;
constexpr int INITIAL_MAX_TEMP = 2025;

string query(const int x) {
    cout << "? " << x << endl;

    string response;
    cin >> response;

    return response;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int left = INITIAL_MIN_TEMP;
    int right = INITIAL_MAX_TEMP;

    while (left <= right) {
        int mid = (left + right) / 2;
        string response = query(mid);

        if (response == "Hot") {
            left = (left + mid) / 2;
            right = mid - 1;
        } else if (response == "Cold") {
            left = mid + 1;
            right = (right + mid) / 2;
        } else {
            cout << "! " << mid << endl;
            return 0;
        }
    }

    cout << "! " << (left + right) / 2 << endl;

    return 0;
}