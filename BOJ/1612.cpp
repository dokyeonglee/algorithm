#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	int n;
	cin >> n;
	
	vector<bool> visited(n);
	
	int mod = 1 % n;
	int answer = 1;
	
	for(int i = 0; i < n; i++){
		if(visited[mod]){
			cout << -1;
			return 0;
		}
		if(mod == 0){
			break;
		}
		visited[mod] = true;
		mod = (mod * 10 + 1) % n;
		answer++;
	}
	
	cout << answer;
	
	return 0;
}