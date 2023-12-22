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
    for(auto& a : arr){
        cin >> a;
    }

    sort(arr.begin(), arr.end());

    long long answer = 1e18;
    long long temp = 0;

    for(int i = 1; i < n; i += 2){
        temp += arr[i] - arr[i - 1];
        answer = min(answer, temp) + arr[i + 1] - arr[i];
    }

    cout << answer;

    return 0;
}