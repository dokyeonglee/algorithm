#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, p;
    cin >> n >> p;

    vector<int> arr(n);
    vector<int> brr(n);

    vector<long long> arr_cnt(1024);
    vector<long long> brr_cnt(1024);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arr_cnt[arr[i]]++;
    }

    for(int i = 0; i < n; i++){
        cin >> brr[i];
        brr_cnt[brr[i]]++;
    }

    vector<long long> cnt(1024);

    long long answer = 0;

    for(int i = 0; i < 1024; i++){
        for(int j = 0; j < 1024; j++){
            answer += (i ^ j) * arr_cnt[i] * brr_cnt[j];
            cnt[i & j] += arr_cnt[i] * brr_cnt[j];
        }
    }

    int idx = 1023;

    while(p > 0){
        long long x = min(p, cnt[idx]);
        answer += x * idx--;
        p -= x;
    }

    cout << answer;

    return 0;
}   