#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    if(n % k == 0){
        cout << 0;
    }else{
        int g = gcd(n, k);
        n /= g;
        k /= g;
        if(k > n / 2){
            k = n - k;
        }
        cout << (long long)n * (k - 1);
    }

    return 0;
}