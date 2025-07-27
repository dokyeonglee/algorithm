#include <iostream>
#include <vector>

using namespace std;

/*
일반성을 일지않고 P[l] < P[r]이라 가정하자.
r보다 크거나 l보다 작은 인덱스의 원소들은 [l, r] 구간에서의 교환에 영향을 받지 않는다.

구간 (l, r) 에서 
    - P[l]보다 작은 원소의 개수를 x,
    - P[r]보다 큰 원소의 개수를 y,라고 하자.

이때,
    - 교환 전 반전 수는 x + y
    - 교환 후에는, 2L + 1 - (x + y)
      (L은 구간 (l, r)의 길이)

즉, 반전 수는 항상 홀수만큼 변하며,
따라서 반전수의 홀짝성은 항상 바뀐다.

구간을 뒤집는 쿼리를 생각해보자.
구간 [l, r]을 뒤집는 것은 다음과 같은 여러 번의 교환으로 볼 수 있다.
    - P[l] <-> P[r], P[l + 1] <-> P[r - 1], ...

총 floor((r - l + 1) / 2)번의 교환이 일어난다.

각 교환은 반전 수의 홀짝성을 바꾸므로,
    - 교환 횟수가 홀수이면 전체 반전 수의 홀짝성이 바뀌고,
    - 짝수면 바뀌지 않는다.

따라서 floor((r - r + 1) / 2)의 홀짝성만 확인하면 된다.
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int inversion_count_parity = 0;

    int n, q;
    cin >> n >> q;

    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;

        if (t == 1) {
            inversion_count_parity ^= 1;
        } else {
            inversion_count_parity ^= (r - l + 1) / 2 % 2;
        }

        cout << inversion_count_parity << '\n';
    }

    return 0;
}