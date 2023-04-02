#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);

    int sum = 0;
    int cnt = 0;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
        cnt += arr[i] % 2;
    }

    if(sum % 3 != 0){
        cout << "NO";
    }else{
        int one = sum / 3 - cnt;
        if(one < 0 or one % 2 == 1){
            cout << "NO";
        }else{
            cout << "YES";
        }
    }

    return 0;
}