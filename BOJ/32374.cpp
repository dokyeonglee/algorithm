#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_largest_remaining_box(vector<int>& boxes, vector<int>& picked) {
    int idx = 0;
    for (const int x : picked) {
        if (boxes[idx] != x) {
            break;
        }
        ++idx;
    }

    return boxes[idx];
}

int find_largest_present(const vector<int>& presents, const int box) {
    auto it = upper_bound(presents.begin(), presents.end(), box);
    return *(it - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> presents(n);
    for (int& present : presents) {
        cin >> present;
    }

    vector<int> boxes(n);    
    for (int& box : boxes) {
        cin >> box;
    }

    vector<int> picked(k);
    for (int& x : picked) {
        cin >> x;
    }

    sort(presents.begin(), presents.end());
    sort(boxes.rbegin(), boxes.rend());
    sort(picked.rbegin(), picked.rend());

    const int largest_remaining_box = find_largest_remaining_box(boxes, picked);
    cout << find_largest_present(presents, largest_remaining_box) << '\n';

    return 0;
}