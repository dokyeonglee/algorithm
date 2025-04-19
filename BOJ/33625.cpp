#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void update(vector<int>& cnt, int x, int add){
    for(int i = 0; i < cnt.size(); i++){
        cnt[i] += add * (x & 1);
        x >>= 1;
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n + 1);

    int zero_cnt = 0;
    int bit = (1 << 31) - 1;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        bit &= arr[i];
        if(arr[i] == 0){
            zero_cnt++;
        }
    }

    if(zero_cnt){
        cout << n - zero_cnt;
        return 0;
    }else if(bit){
        cout << -1;
        return 0;
    }

    vector<int> cnt(31);

    int left = 0;
    int right = 0;

    int answer = 1e9;

    update(cnt, arr[0], 1);

    while(right < n){
        bool check = true;
        for(int i = 0; i < cnt.size(); i++){
            if(cnt[i] == right - left + 1){
                check = false;
                break;
            }
        }
        if(check){
            answer = min(answer, right - left);
            update(cnt, arr[left++], -1);
        }else{
            update(cnt, arr[++right], 1);
        }
    }

    answer += n - 1;
    cout << answer;

    return 0;

}