#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    long long sum = 0;
    int max_amount = 0;

    while(n--){
        int x;
        cin >> x;
        sum += x;
        max_amount = max (max_amount, x);
    }

    if(sum - max_amount < max_amount){
        cout << 2 * max_amount - sum;
    }else{
        cout << sum % 2;
    }

    return 0;

}