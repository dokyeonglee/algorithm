#include <iostream>
#include <vector>

using namespace std;

const long long mod = 1e9 + 7;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    long long answer = 0;

    while(n--){

        int x, k;
        cin >> x >> k;

        long long p = 1;

        for(int i = 0; i < 30; i++){
            if(k & (1 << i)){
                answer += p;
            }
            p = p * x % mod;
        }

    }

    answer %= mod;

    cout << answer;

    return 0;

}