#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

constexpr double PI = 3.14159265358979;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    cout << fixed;
    cout.precision(5);

    while (t--) {
        int n;
        cin >> n;

        double answer = 0;
        for (int i = 0; i < n; ++i) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            double theta1 = atan2(y1, x1);
            double theta2 = atan2(y2, x2);
            double theta = abs(theta1 - theta2);
            if (theta >= PI) {
                theta = 2 * PI - theta;
            }

            answer += theta / (2 * PI);
        }

        answer = round(100000 * answer) / 100000;
        cout << answer << '\n';
    }

    return 0;
}