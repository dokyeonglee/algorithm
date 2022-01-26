#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<long long> fac(21, 1);
	for(int i = 2; i <= 20; i++){
		fac[i] = fac[i - 1] * i;
	}
		
	int n;
	cin >> n;
	
	int x;
	cin >> x;

	if(x == 1){
		
		long long k;
		cin >> k;
		
		vector<int> answer(n);
		vector<bool> visited(21, false);
		
		for(int i = 0; i < n; i++){
			for(int j = 1; j <= n; j++){
				if(visited[j]){
					continue;
				}
				if(k > fac[n - i - 1]){
					k -= fac[n - i - 1];
				}else{
					answer[i] = j;
					visited[j] = true;
					cout << answer[i] << " ";
					break;
				}
			}
		}
	}else{
		
		vector< int> arr(n);
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		
		long long answer = 0;
		vector<bool> visited(21, false);
		
		for(int i = 0; i < n; i++){
			for(int j = 1; j < arr[i]; j++){
				if(visited[j]){
					continue;
				}
				answer += fac[n - 1 - i];
			}
			visited[arr[i]] = true;
		}
		
		cout << answer + 1;
		
	}
	
	return 0;
}