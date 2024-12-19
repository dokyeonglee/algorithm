#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, q;
    cin >> n >> k >> q;

    vector<int> arr(n);
    for(auto& a : arr){
        cin >> a;
        a %= k;
    }

    sort(arr.begin(), arr.end());

    int s = 0;

    while(q--){
        int x;
        cin >> x;
        s = (s + x) % k;
        auto it = lower_bound(arr.begin(), arr.end(), k - s);
        if(it == arr.begin()){
            cout << arr.back() + s << " ";
        }else{
            cout << *prev(it) + s << " ";
        }
    }

    return 0;
}