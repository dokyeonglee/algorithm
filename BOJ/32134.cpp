#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, h, s;
    cin >> n >> h >> s;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    double a = 0;
    double b = 0;
    double c = 0;

    if(n * h < 2 * s){
        double x = 2.0 * s / n - h;
        for(int i = 1; i <= n; i++){
            c += arr[i] * x;
        }
        h -= x;
        s -= x * n;
    }

    double m = 2.0 * s / n / n;

    for(int i = 1; i <= n; i++){
        a += m * (2 * i - 1) / 2 * arr[i];
        b += m * (2 * i - 1) / 2 * arr[n + 1 - i];
    }

    cout << fixed;
    cout.precision(10);
    cout << min(a, b) + c;

    return 0;
}