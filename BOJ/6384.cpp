#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for(int test_case = 1; test_case <= t; test_case++){
        cout << "Scenario #" << test_case << ":\n";

        int i = 0, e = 0;
        double area = 0;

        int n;
        cin >> n;

        vector<pair<int, int>> arr(n + 2);
        for(int i = 1; i <= n; i++){
            cin >> arr[i].first >> arr[i].second;
            e += abs(gcd(arr[i].first, arr[i].second));
            arr[i].first += arr[i - 1].first;
            arr[i].second += arr[i - 1].second;
        }

        arr[n + 1] = arr[1];

        for(int i = 1; i <= n; i++){
            area += arr[i].first * arr[i + 1].second - arr[i].second * arr[i + 1].first;
        }

        area = fabs(area) / 2.0;
        i = area - e / 2.0 + 1;
        cout << fixed;
        cout.precision(1);
        cout << i << " " << e << " " << area << "\n\n";
    }

    return 0;
}