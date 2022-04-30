#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> answer;

void dfs(long long x){
	answer.push_back(x);
	if(x % 10 == 0){
		return;	
	}
	for(int i = x % 10 - 1; i >= 0; i--){
		dfs(x * 10 + i);
	}
}

int main() {
	
	for(int i = 0; i < 10; i++){
		dfs(i);
	}
	sort(answer.begin(), answer.end());
	
	int n;
	cin >> n;

	if(n > answer.size()){
		cout << -1;
	}else{
		cout << answer[n - 1];
	}
	
	return 0;
}