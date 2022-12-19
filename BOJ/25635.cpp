#include <iostream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    long long sum = 0;
    long long _max = 0;

    for(int i = 0; i < n; i++){
        long long x;
        cin >> x;
        sum += x;
        _max = max(_max, x);
    }

    if(sum - _max < _max - 1){
        cout << 2 * (sum - _max) + 1;
    }else{
        cout << sum;
    }

    return 0;
}