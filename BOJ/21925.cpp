#include <iostream>
#include <vector>

using namespace std;

bool is_palindrome(const vector<int>& arr, int left, int right) {
    while (left <= right) {
        if (arr[left++] != arr[right--]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int& a : arr) {
        cin >> a;
    }

    int left = 0;
    int right = 0;
    int answer = 0;
    while (right + 1 < n) {
        ++right;
        if ((right - left) % 2) {
            if (is_palindrome(arr, left, right)) {
                ++answer;
                left = right + 1;
            }
        }
    }

    if (left < n) {
        answer = -1;
    }

    cout << answer;

    return 0;
}