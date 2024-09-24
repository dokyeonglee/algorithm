#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const int mod = 1e9 + 7;

    int k;
    cin >> k;

    int p, q, r, s;
    cin >> p >> q >> r >> s;

    long long a;
    cin >> a;

    long long answer = a;

    k--;

    for(int i = 0; i < k; i++){
        a = ((p + r) * a + (q + s) * ((1ll << i) % mod)) % mod;
        answer = (answer + a) % mod;
    }

    cout << answer;

    return 0;
}