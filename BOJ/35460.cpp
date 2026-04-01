#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    long long answer = 0;
    if (k == 0) {
        answer = n;
    } else if (k == 1) {
        answer = 2 * n + 2;
    } else {
        vector<int> route(k + 2);
        route[0] = 1;
        route[k + 1] = n;

        int l = 2;
        int r = k + 1;
        for (int i = 1; l <= r; ++i) { 
            if (i % 2) {
                route[i] = r--;
                route[k + 1 - i] = l++;
            } else {
                route[i] = l++;
                route[k + 1 - i] = r--;
            }
        }

        for (int i = 1; i < route.size(); ++i) {
            answer += 1ll * route[i] * route[i - 1];
        }
    }

    cout << answer;

    return 0;
}