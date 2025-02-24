#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    if(b * c > a * d){
        swap(a, c);
        swap(b, d);
    }

    int cnt = min(a / gcd(a, c), n / c);

    long long answer = (n + c - 1) / c * d;

    for(int i = 0; i <= cnt; i++){
        long long j = (n - c * i + a - 1) / a;
        answer = min(answer, b * j + d * i);
    }

    cout << answer;

    return 0;

}