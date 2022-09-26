#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int>& psum, vector<vector<int>>& dp, int idx, int e){
    
    if(psum.back() - psum[idx - 1] < e){
        return 987654321;
    }

    if(e <= 0){
        return 0;
    }

    int& ret = dp[idx][e];
    if(ret != -1){
        return ret;
    }

    int x = psum[idx] - psum[idx - 1];

    return ret = min(solve(psum, dp, idx + 1, e), x + solve(psum, dp, idx + 1, e - x));
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n, e;
		cin >> n >> e;

        vector<int> psum(n + 1);

		for(int i = 1; i <= n; i++){
			cin >> psum[i];
			psum[i] += psum[i - 1];
		}

        e = (e + 1) / 2;

        if(e == 0){
            cout << "0\n";
        }else if(psum[n] < e){
			cout << "FULL\n";
		}else if(psum[n] == e){
			cout << e << "\n";
		}else{
            vector<vector<int>> dp(n + 1, vector<int>(e + 1, -1));
            cout << solve(psum, dp, 1, e) << "\n";
        }
    }

    return 0;
}