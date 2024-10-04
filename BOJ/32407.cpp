#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> arr(17);

    while(n--){
        int x;
        cin >> x;
        arr[__builtin_ctz(x)]++;
    }

    for(int i = 1; i <= 16; i++){
        arr[i] += 2 * arr[i - 1];
    }

    cout << (arr[16] + (1 << 16) - 1) / (1 << 16);

    return 0;
}