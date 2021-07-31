#include <iostream> 
#include <vector> 

using namespace std; 

int main() { 
	
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	
	int r, c; 
	cin >> r >> c; 
	
	vector<vector<int>> mine(2 * r + 5, vector<int>(2 * c + 5)); 
	for(int i = 1; i <= r; i++){ 
		string str;
		cin >> str;
		for(int j = 1; j <= str.size(); j++){
			mine[i][j] = str[j - 1] - '0';
		}
	} 
	
	vector<vector<vector<int>>> dp(r + 5, vector<vector<int>>(c + 5, vector<int>(4))); 
	
	for(int i = 1; i <= r; i++){ 
		for(int j = 1; j <= c; j++){ 
			if(mine[i][j] == 1){ 
				dp[i][j][0] = dp[i - 1][j - 1][0] + 1; 
				dp[i][j][1] = dp[i - 1][j + 1][1] + 1; 
			} 
		} 
	} 
	
	for(int i = r; i >= 1; i--){ 
		for(int j = c; j >= 1; j--){ 
			if(mine[i][j] == 1){ 
				dp[i][j][2] = dp[i + 1][j - 1][2] + 1; 
				dp[i][j][3] = dp[i + 1][j + 1][3] + 1; 
			} 
		} 
	} 
	
	int answer = 0; 
	
	for(int i = 1; i <= r; i++){ 
		for(int j = 1; j <= c; j++){
            
            if(answer < min(dp[i][j][2], dp[i][j][3])){
			    for(int k = 1; k <= min(dp[i][j][2], dp[i][j][3]); k++){//(i, j)가 윗 꼭지점 
				    if(mine[i + 2 * (k - 1)][j] and dp[i + 2 * (k - 1)][j][0] >= k and dp[i + 2 * (k - 1)][j][1] >= k){ 
					    answer = max(answer, k);
				    }
			    }
            }
			
            if(answer < min(dp[i][j][1], dp[i][j][3])){
			    for(int k = 1; k <= min(dp[i][j][1], dp[i][j][3]); k++){//(i, j)가 왼쪽 꼭지점 
				    if(mine[i][j + 2 * (k - 1)] and dp[i][j + 2 * (k - 1)][0] >= k and dp[i][j + 2 * (k - 1)][2] >= k){ 
					    answer = max(answer, k); 
				    } 
			    }
            }
		} 
	} 
	
	cout << answer; 
	
	return 0; 

}