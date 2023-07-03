#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<long long> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    long long answer = -1e18;
    long long current_max = -1e18;
    long long current_min = 1e18;

    for(int i = 1; i <= n; i++){
        long long current_n_pole = arr[i] - k * i;
        long long current_s_pole = arr[i] + k * i;
        answer = max(answer, current_n_pole - current_min);
        answer = max(answer, current_max - current_s_pole);
        current_min = min(current_min, current_n_pole);
        current_max = max(current_max, current_s_pole);
    }

    cout << answer;

    return 0;
}