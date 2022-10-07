#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> triangle(n + 5, vector<int>(n + 5));
	
	for(int i = 0; i < m; i++){
		int a, b, x;
		cin >> a >> b >> x;
		triangle[a][b]++;
		triangle[a][b + 1]--;
		triangle[a + x + 1][b]--;
		triangle[a + x + 2][b + 1]++;
		triangle[a + x + 1][b + x + 2]++;
		triangle[a + x + 2][b + x + 2]--;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			triangle[i][j] += triangle[i][j - 1];
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			triangle[j][i] += triangle[j - 1][i];			
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			triangle[i][j] += triangle[i - 1][j - 1];
		}
	}
	
	int answer = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			answer += (triangle[i][j] > 0);
		}
	}
	
	cout << answer;
	
	return 0;
}