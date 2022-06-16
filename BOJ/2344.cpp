#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> arr(n + 2, vector<int>(m + 2));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> arr[i][j];
		}
	}
	
	for(int i = 1; i <= 2 * (n + m); i++){
		int dr, dc;
		int r, c;
		if(i <= n){
			r = i;
			c = 0;
			dr = 0;
			dc = 1;
		}else if(i <= n + m){
			r = n + 1;
			c = i - n;
			dr = -1;
			dc = 0;
		}else if(i <= 2 * n + m){
			r = 2 * n + m + 1 - i;
			c = m + 1;
			dr = 0;
			dc = -1;
		}else{
			r = 0;
			c = 2 * n + 2 * m + 1 - i;
			dr = 1;
			dc = 0;
		}
		do{
			r += dr;
			c += dc;
			if(arr[r][c] == 1){
				swap(dr, dc);
				dr = -dr;
				dc = -dc;
			}
		}while(r >= 1 and r <= n and c >= 1 and c <= m);
		
		if(c == 0){
			cout << r << " ";
		}else if(c == m + 1){
			cout << 2 * n + m + 1 - r << " ";
		}else if(r == 0){
			cout << 2 * n + 2 * m + 1 - c << " ";
		}else if(r == n + 1){
			cout << n + c << " ";
		}
		
	}
	
	return 0;
}