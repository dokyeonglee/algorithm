#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b){
    return b ? gcd(b, a % b) : a;
}

pair<long long, long long> compute_max_ratio(const vector<int>& x, const vector<int>& y) {
    long long numerator = y[0];
    long long denominator = x[0];

    for (int i = 1; i < x.size(); i++) {
        if (numerator * x[i] < denominator * y[i]) {
            numerator = y[i];
            denominator = x[i];
        }
    }

    long long g = gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;
    return {numerator, denominator};
}

int compute_max_length_for_ratio(const vector<int>& x, const vector<int>& y, long long numerator, long long denominator) {
    int max_length = 0;
    int current_length = 0;

    for (int i = 0; i < x.size(); i++) {
        if (numerator * x[i] == denominator * y[i]) {
            current_length++;
        } else {
            max_length = max(max_length, current_length);
            current_length = 0;
        }
    }

    max_length = max(max_length, current_length);
    return max_length;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> x(n);
    vector<int> y(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    auto [numerator, denominator] = compute_max_ratio(x, y);
    int max_ratio_length = compute_max_length_for_ratio(x, y, numerator, denominator);

    cout << numerator << ' ' << denominator << '\n';
    cout << max_ratio_length;

    return 0;

}