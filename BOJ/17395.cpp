#include <iostream>
#include <vector>

using namespace std;

long long get_msb(long long x){

    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x |= x >> 32;
    
    return (x + 1) >> 1;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long x, n;
    cin >> x >> n;

    int cnt = __builtin_popcountll(x);

    if(cnt < n){
        cout << -1;
        return 0;
    }

    long long msb = get_msb(x);

    while(n > 1){
        if(x & msb){
            n--;
            x -= msb;
            cout << x << " ";
        }
        msb >>= 1;
    }

    cout << 0;

    return 0;
}