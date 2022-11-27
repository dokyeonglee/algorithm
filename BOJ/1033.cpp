#include <iostream>
#include <vector>

using namespace std;

vector<long long> answer(10);

long long gcd(long long a, long long b){
	return b ? gcd(b, a % b) : a;
}

void dfs(vector<vector<int>>& arr, vector<bool>& visited, int x, long long y){
	
	visited[x] = true;
	answer[x] = y;
	
	for(int i = 0; i < arr[x].size(); i++){
		if(!visited[i] and arr[x][i] != 0){
			dfs(arr, visited, i, y * arr[i][x] / arr[x][i]);
		}
	}
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<int>> arr(n, vector<int>(n));
	vector<bool> visited(n);
	
	int a, b, p, q;
	long long mul = 1;
	for(int i = 0; i < n - 1; i++){
		cin >> a >> b >> p >> q;
		int g = gcd(p, q);
		p /= g;
		q /= g;
		mul *= p * q;
		arr[a][b] = p;
		arr[b][a] = q;
	}
	
	dfs(arr, visited, 0, mul);
	
	long long g = mul;
	for(int i = 0; i < n; i++){
		g = gcd(g, answer[i]);
	}
	
	for(int i = 0; i < n; i++){
		cout << answer[i] / g << " ";
	}
	
	return 0;
}