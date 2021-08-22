#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<int>> v(7);
	int sum = 0;
	int x;
	
	for(int i = 0; i < n; i++){
		cin >> x;
		sum += x;
		sum %= 7;
		v[sum].push_back(i);
	}
	
	int answer = 0;
	
	if(v[0].size() > 0 and v[0].back() == n - 1){
		answer = n;
	}else{
		for(int i = 0; i < 7; i++){
			if(v[i].size() > 0){
				answer = max(answer, v[i].back() - v[i].front());
			}
		}
	}
	
	cout << answer;
	
	return 0;
}