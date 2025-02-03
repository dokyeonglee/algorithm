#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> cnt(m);
    vector<int> cnt2(m);

    long long answer = 0;

    for(int i = 0; i < n; i++){
        int sum = 0;
        int sum2 = 0;
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 'E'){
                cnt[j]++;
            }
            sum += cnt[j];
            if(arr[i][j] == 'S'){
                cnt2[j] += sum;
                cnt2[j] %= mod;
            }
            sum2 += cnt2[j];
            sum2 %= mod;
            if(arr[i][j] == 'M'){
                answer += sum2;
                answer %= mod;
            }
        }
    }

    cout << answer;

    return 0;

}