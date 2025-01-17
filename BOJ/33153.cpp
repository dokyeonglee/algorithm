#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(auto& a : arr){
        cin >> a;
    }

    int bit = (1 << 29);
    int answer = 0;
    int x = 0;

    while(bit > 0){
        while(x & bit){
            answer |= bit;
            bit >>= 1;
        }
        if(answer & bit){
            bit >>= 1;
            continue;
        }
        answer ^= bit;
        int now = 0;
        int cnt = 0;
        x = -1;
        for(int i = 0; i < n; i++){
            now |= arr[i];
            if((now & answer) == answer){
                x &= now;
                now = 0;
                cnt++;
            }
        }
        if(cnt < n - k){
            answer ^= bit;
            x = 0;
        }else{
            if(now){
                x &= now;
            }
        }
        bit>>= 1;
    }

    cout << answer;

    return 0;

}