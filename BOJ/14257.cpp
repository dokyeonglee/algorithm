#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long s, x;
    cin >> s >> x;

    if(s < x or (s - x) % 2 == 1){
        cout << 0;
    }else{
        long long a = (s - x) / 2;
        long long answer = 1ll << __builtin_popcountll(x);
        if(a & x){
            answer = 0;
        }else if(s == x){
            answer -= 2;
        }
        cout << answer;
    }

    return 0;
}