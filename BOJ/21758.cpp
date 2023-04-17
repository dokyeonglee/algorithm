#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    int answer = 0;

    for(int i = 2; i < n; i++){
        answer = max(answer, arr[n] - arr[1] + arr[n] - arr[i] - (arr[i] - arr[i - 1]));
    }

    for(int i = n - 1; i > 0; i--){
        answer = max(answer, arr[n - 1] + arr[i - 1] - (arr[i] - arr[i - 1]));
    }

    for(int i = 2; i < n; i++){
        answer = max(answer, arr[i] - arr[1] + arr[n - 1] - arr[i - 1]);
    }

    cout << answer;

    return 0;
}