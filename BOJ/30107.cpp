#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    vector<int> arr(500001);
    vector<int> brr(500001);

    int idx = 1;
    int cnt = 1;

    while(idx <= 500000){
        if(idx >= (1 << (cnt + 1)) - 1){
            cnt++;
        }
        arr[idx] = cnt;
        brr[idx] = __builtin_popcount(idx - (1 << cnt) + 1);
        idx++;
    }

    for(int i = 1; i <= 500000; i++){
        arr[i] += arr[i - 1];
        brr[i] += brr[i - 1];
    }

    while(t--){
        long long n, a, b;
        cin >> n >> a >> b;
        if(a < b){
            swap(a, b);
        }
        long long answer = a * arr[n] + b * brr[n];
        cout << answer << "\n";
    }

    return 0;
}