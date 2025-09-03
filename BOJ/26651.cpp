#include <iostream>
#include <vector>

using namespace std;

constexpr char BASE_GRAMPAN[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
constexpr int MAX_A_COUNT = 31622;

string build_grampan_block(const int a_count, const int z_count) {
    return string(a_count - 1, 'A') + BASE_GRAMPAN + string(z_count - 1, 'Z');
}

string build_grampan(const int x) {
    if (x == 0) {
        return "X";
    }

    const int q = x / MAX_A_COUNT;
    const int r = x % MAX_A_COUNT;

    string grampan;

    if (q > 0) {
        grampan = build_grampan_block(MAX_A_COUNT, q);
    }

    if (r > 0) {
        grampan += build_grampan_block(r, 1);
    }

    return grampan;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;

    cout << build_grampan(x) << '\n';

    return 0;
}