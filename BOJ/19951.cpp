#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<long long> arr(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	
	vector<long long> add(n + 2);
	for(int i = 1; i <= m; i++){
		int a, b, k;
		cin >> a >> b >> k;
		add[a] += k;
		add[b + 1] -= k;
	}
	
	for(int i = 1; i <= n; i++){
		add[i] += add[i - 1];
	}
	
	for(int i = 1; i <= n; i++){
		cout << arr[i] + add[i] << " ";
	}
	
	return 0;
}