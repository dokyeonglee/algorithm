#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<long long> cnt(1024);
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        int bit = 0;
        for(int j = 0; j < 10; j++){
            bit |= 1 << (str[j] - '0');
        }
        cnt[bit]++;
    }

    long long answer = 0;

    for(int i = 0; i < 1024; i++){
        for(int j = i; j < 1024; j++){
            if(__builtin_popcount(i | j) == k){
                if(i == j){
                    answer += cnt[i] * (cnt[i] - 1) / 2;
                }else{
                    answer += cnt[i] * cnt[j];
                }
            }
        }
    }

    cout << answer;

    return 0;
}