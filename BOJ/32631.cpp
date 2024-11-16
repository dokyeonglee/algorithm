#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<long long> arr(n + 5);
    vector<long long> brr(n + 5);

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    for(int i = 1; i <= n; i++){
        cin >> brr[i];
        brr[i] += brr[i - 1];
    }

    vector<vector<long long>> minimum_sum_of_weight(k + 1, vector<long long>(2, 1e18));

    for(int i = 0; i <= k; i++){
        for(int j = n - i; j <= n; j++){
            minimum_sum_of_weight[i][0] = min(minimum_sum_of_weight[i][0], arr[j] - arr[j - n + i]);
            minimum_sum_of_weight[i][1] = min(minimum_sum_of_weight[i][1], brr[j] - brr[j - n + i]);
        }
    }

    long long answer= 1e18;

    for(int i = 0; i <= k; i++){
        answer = min(answer, max(minimum_sum_of_weight[i][0], minimum_sum_of_weight[k - i][1]));
    }

    cout << answer;

    return 0;
}