#include <iostream>
#include <vector>

using namespace std;

int get_height(long long x, int max_height){

    int left = 1;
    int right = max_height;
    int height = 1;

    while(left <= right){
        long long mid = (left + right) / 2;
        if(mid * (mid - 1) / 2 < x){
            height = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    return height;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int max_height;
    cin >> max_height;

    int q, r;
    cin >> q >> r;


    vector<double> dp(max_height + 3);

    long long a, b;

    while(q--){
        cin >> a >> b;
        long long height = get_height(a, max_height);
        int left = a - height * (height - 1) / 2;
        int right = left + (max_height - (height - 1));
        dp[left] += (double)b / (right - left + 1);
        dp[right + 1] -= (double)b / (right - left + 1);
    }

    for(int i = 1; i <= max_height + 1; i++){
        dp[i] += dp[i - 1];
    }

    for(int i = 1; i <= max_height + 1; i++){
        dp[i] += dp[i - 1];
    }

    while(r--){
        cin >> a >> b;
        cout << dp[b] - dp[a - 1] << "\n";
    }

    return 0;

}