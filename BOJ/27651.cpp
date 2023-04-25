#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    long long answer = 0;

    int idx = n;

    for(int i = 1; i <= n; i++){
        long long a = arr[i];
        if(arr[n] - a < 2 * a + 3){
            break;
        }
        while(idx >= 1 and arr[n] - arr[idx - 1] <= a){
            idx--;
        }
        if(idx <= i){
            break;
        }
        int b = lower_bound(arr.begin(), arr.end(), a + (arr[n] - a) / 2 + 1) - arr.begin();
        answer += max(0, idx - b);
    }

    cout << answer;

    return 0;
}