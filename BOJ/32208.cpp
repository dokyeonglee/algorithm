#include <iostream>
#include <vector>

using namespace std;

/*
나이트의 이동을 하나의 벡터라고 생각해보자.

벡터들의 선형 결합으로 다음과 같은 기저 벡터들을 만들 수 있다.
v1 = (1, 1, 0), v2 = (1, 0, 1), v3 = (0, 1, 1)를 만들 수 있다.
(v1, v2, v3를 만들 수 있으면 -v1, -v2, -v3를 만들 수 있음은 자명하다.);

    ex)
        v1 = (1, 2, 3) + (3, 1, -2) + (-3, -2, -1)
        v2 = (1, 3, 2) + (3, -2, 1) + (-3, -1, -2)
        v3 = (3, 1, 2) + (-2, 3, 1) + (-1, -3, -2)


이제 목표 좌표 (x, y, z)를 기저로 표현해보자.
이 때 다음과 같은 선형 결합이 성립한다.
    (x, y, z) = {(x + y - z) / 2} * v1 + {(x - y + z) / 2} * v2 + {(-x + y + z) / 2} * v3

즉, (x, y, z)에 도달하려면, 선형 결합의 계수가 모두 정수여야 한다.
이는 (x + y - z), (x - y + z), (-x + y + z) 가 모두 짝수임을 의미한다.
이 세수는 (x + y + z)와 같은 홀짝성을 갖는다.
따라서 (x + y + z)가 짝수면 (x, y, z)에 도달 가능하다.

시작점이 원점이 아닌 일반적인 경우로 확장해보자.
시작점과 도착점을 동시에 평행이동하여 시작점을 원점으로 옮기면 동일한 문제가 된다.
결과적으로, 어떤 좌표 (x, y, z)에 도달 가능하려면, 그 좌표의 (x + y + z)의 홀짝성이 시작 정점과 같아야 한다.
*/

bool reachable(const int x, const int y, const int z, const int parity = 0) {
    return (x + y + z) % 2 == parity;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;

        if (reachable(x, y, z)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}