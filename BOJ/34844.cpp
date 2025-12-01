#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<bool> picked(1024);
    if (n % 2 == 0) {
        cout << "second min" << endl;
    } else {
        cout << "second max" << endl;
    }

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        if (picked[x]) {
            cout << -1 << endl;
            return 0;
        }
        picked[x] = true;
        picked[x ^ 1023] = true;

        cout << (x ^ 1023) << endl;
    }
    

    return 0;
}