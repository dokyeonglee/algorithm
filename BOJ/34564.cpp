#include <iostream>

using namespace std;
using ll = long long;

/*
- 길이가 k이고 0이 x개 있는 이진 문자열 A와 
  길이가 (n - k)이고 0이 (k - x)개 있는 문자열 B가 있다고 하자.

- 이 때 A를 뒤집으면 A의 0의 개수는 (k - x)개 가 되어
  B의 0의 개수와 같아진다.

- 따라서 항상 조건을 만족할 수 있으며,
  이를 나타내면 (a1 = 0, a2 = k, b1 = n - k, b2 = 0) 이 된다.
*/

int main() {
    ll n, k;
    cin >> n >> k;

    ll a1 = 0;
    ll a2 = k;
    ll b1 = n - k;
    ll b2 = 0;

    cout << a1 << ' ' << a2 << ' ' << b1 << ' ' << b2 << '\n';

    return 0;
}