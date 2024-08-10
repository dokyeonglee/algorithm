#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    long long sum = 0;

    vector<long long> arr(n);
    for(auto& a : arr){
        cin >> a;
        sum += a;
    }

    sort(arr.begin(), arr.end());

    sum -= m;

    long long answer = 0;

    for(int i = 0; i < n; i++){
        long long temp = min(arr[i], sum / (n - i));
        answer += temp * temp;
        sum -= temp;
    }

    cout << answer;

    return 0;
}