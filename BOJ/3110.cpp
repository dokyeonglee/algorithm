#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int b, c, d;
    cin >> b >> c >> d;

    int a1, a2, e1, e2;
    cin >> a1 >> a2 >> e1 >> e2;

    int s = (a1 * c) / a2 + 1;
    int e = (e1 * c - 1) / e2;

    long long answer = 0;

    for(int i = s; i <= e; i++){
        answer += ((e1 * d - 1) / e2 - i * d / c) * ((i * b - 1) / c - (a1 * b) / a2);
    }

    cout << answer;

    return 0;
}