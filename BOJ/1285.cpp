#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < n; j++){
            arr[i] |= (str[j] == 'H') << j;
        }
    }

    int answer = 987654321;

    for(int i = 0; i < (1 << n); i++){
        int result = 0;
        for(int j = 0; j < n; j++){
            int cnt = __builtin_popcount(arr[j] ^ i);
            result += min(cnt, n - cnt);
        }
        answer = min(answer, result);
    }

    cout << answer;

    return 0;
}