#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> arr(n);
    for(long long& a : arr){
        cin >> a;
    }

    sort(arr.begin(), arr.end());

    long long answer = 0;

    for(int i = 0; i < n - 1; i++){
        answer ^= (arr[i] * arr[i]) ^ (arr[i] * arr[i + 1]);
    }

    answer ^= arr[n - 1] * arr[n - 1];

    cout << answer;

    return 0;
}