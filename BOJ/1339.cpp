#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<string> words(n);
	for(int i = 0; i < n; i++){
		cin >> words[i];
	}
	
	vector<int> mem(26);
	for(int i = 0; i < n; i++){
		
		int temp = 1;
		
		for(int j = words[i].size() - 1; j >= 0; j--){
			mem[words[i][j] - 'A'] += temp;
			temp *= 10;
		}
		
	}
	
	sort(mem.begin(), mem.end(), greater<int>());
	
	int answer = 0;
	for(int i = 0; i < 10; i++){
		answer += mem[i] * (9 - i);
	}
	
	cout << answer;
	
	return 0;
}