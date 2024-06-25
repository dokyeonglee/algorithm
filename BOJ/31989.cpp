#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> arr(2 * n + 2);

    for(int i= 1; i < arr.size(); i++){
        cin >> arr[i];
    }

    long long answer = 0;

    int left = n + 1;
    int right = n + 1;

    for(int i = 0; i < m; i++){
        int p, w;
        cin >> p >> w;
        left = min(left, p);
        right = max(right, p);
        answer += 1ll * abs(arr[n + 1] - arr[p]) * w;
    }

    answer += 2 * (arr[right] - arr[left]);

    cout << answer;

    return 0;
}