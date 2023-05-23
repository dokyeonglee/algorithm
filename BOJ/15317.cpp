#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, m, x;
    cin >> n >> m >> x;

    vector<long long> arr(n);
    for(long long i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<long long> budget(m);
    for(long long i = 0; i < m; i++){
        cin >> budget[i];
    }

    sort(arr.begin(), arr.end());
    sort(budget.begin(), budget.end(), greater<>());

    long long answer = 0;

    long long left = 0;
    long long right = min(n, m);

    while(left <= right){

        long long mid = (left + right) / 2;
        long long sum = 0;

        for(int i = 0; i < mid; i++){
            sum += max(0ll, arr[mid - 1 - i] - budget[i]);
        }
        
        if(sum <= x){
            answer = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }

    }

    cout << answer;

    return 0;
}