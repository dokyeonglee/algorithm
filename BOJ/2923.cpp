#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int>& cnt_a, vector<int>& cnt_b){

    int a_index = 1;
    int b_index = 99;

    int result = 0;
    int remain_a = cnt_a[a_index];
    int remain_b = cnt_b[b_index];

    while(b_index > 0 and a_index < 100){
        while(a_index + 1 < 100 and remain_a == 0){
            remain_a = cnt_a[++a_index];
        }
        while(b_index - 1 > 0 and remain_b == 0){
            remain_b = cnt_b[--b_index];
        }
        if(a_index == 99 and cnt_b[a_index] == 0){
            break;
        }
        if(b_index == 1 and cnt_b[b_index] == 0){
            break;
        }
        int matched = min(remain_a, remain_b);
        remain_a -= matched;
        remain_b -= matched;
        result = max(result, a_index + b_index);
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> cnt_a(100);
    vector<int> cnt_b(100);

    int t;
    cin >> t;

    while(t--){
        int a, b;
        cin >> a >> b;
        cnt_a[a]++;
        cnt_b[b]++;
        cout << solve(cnt_a, cnt_b) << "\n";
    }


    return 0;
}