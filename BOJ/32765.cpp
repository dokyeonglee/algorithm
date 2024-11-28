#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<long long> arr(40000);

    cin >> arr[0];

    for(int i = 1; i < arr.size(); i++){
        arr[i] = arr[i - 1] + i - arr[i - 1] % i;
    }

    long long k = arr.back() / (arr.size() - 1);

    int q;
    cin >> q;

    while(q--){
        int x;
        cin >> x;
        if(x < arr.size()){
            cout << arr[x] << "\n";
        }else{
            cout << x * k << "\n";
        }
    }

    return 0;
}