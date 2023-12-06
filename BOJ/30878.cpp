#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int a =  3 * (60 - n) * n * n + n * n * n;
    int g = gcd(a, 60 * 60 * 60);

    cout << a / g << "/" << 60 * 60 * 60 / g;

    return 0;
}