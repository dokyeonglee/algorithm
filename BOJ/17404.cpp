#include <iostream>
#include <vector>

using namespace std;

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
    int n;
    cin >> n;
    
    vector<vector<int>> rgb(n + 1, vector<int>(3));
    
    for(int i = 1; i <= n; i++){
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    }
    
    int answer = 987654321;
    vector<vector<int>> dp(n + 1, vector<int>(3));
    
    for(int i = 0; i < 3; i++){
    	
    	for(int j = 0; j < 3; j++){
    		if(i == j){
    			dp[1][j] = rgb[1][j];
    		}else{
    			dp[1][j] = 987654321;
    		}
    	}
    	
    	for(int j = 2; j <= n; j++){
    		dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + rgb[j][0];
    		dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + rgb[j][1];
    		dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + rgb[j][2];
    	}
    	
    	for(int j = 0; j < 3; j++){
    		if(i == j){
    			continue;
    		}
    		answer = min(answer, dp[n][j]);
    	}
    	
    }
    
    cout << answer;
    
    return 0;
}