#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    if(n <= k){
        cout << 0;
    }else{
        int answer = 0;
        while(1){
            if(__builtin_popcount(n) <= k){
                break;
            }
            answer += n & -n;
            n += n & -n;
        }
        cout << answer;
    }

    return 0;
}