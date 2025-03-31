#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b){
    return b ? gcd(b, a % b) : a;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long s0, x, m, d, k;
    cin >> s0 >> x >> m >> d >> k;

    long long g = gcd(x, m);

    long long y = (m - g + s0 % g);

    if(y == 0){
        cout << 0;
        return 0;
    }

    cout << (d - 1) / (k / y);

    return 0;

}