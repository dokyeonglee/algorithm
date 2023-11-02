#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> arr(2 * n);

    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        int x;
        cin >> x;
        arr[2 * i] = x;
        for(int j = 1; j < k - 1; j++){
            cin >> x;
        }
        cin >> x;
        arr[2 * i + 1] = x;
    }

    sort(arr.begin(), arr.end());

    cout << arr[n - 1];

    return 0;
}