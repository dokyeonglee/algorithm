#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> t(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> t[i];
    }

    vector<long long> arr(n + 1);

    long long answer = 0;

    for(int i = 1; i <= n; i++){
        long long diff = t[i] - arr[i];
        answer += abs(diff);
        for(int j = i; j <= n; j += i){
            arr[j] += diff;
        }
    }

    cout << answer;

    return 0;
}