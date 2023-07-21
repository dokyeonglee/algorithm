#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> cnt(n + 1);

    int answer = 0;
    int q = 0;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        answer += arr[i];
        q = max(q, arr[i] * ++cnt[arr[i]]);
    }

    sort(arr.begin(), arr.end());

    cout << answer + q << "\n";

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }


    return 0;
}