#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> happy(n + 1);
	vector<int> fatigue(n + 1);
	
	for(int i = 1; i <= n; i++){
		cin >> happy[i] >> fatigue[i];
	}
	
	vector<int> min_happy(n + 2, 987654321);
	vector<int> max_happy(n + 2, -1);
	vector<int> min_fatigue(n + 2, 987654321);
	vector<int> max_fatigue(n + 2, -1);
	
	for(int i = 1; i <= n; i++){
		if(happy[i] == 0){
			min_happy[i] = min_happy[i - 1];
		}else{
			min_happy[i] = min(min_happy[i - 1], happy[i]);
		}
		if(happy[n + 1 - i] == 0){
			max_happy[n + 1 - i] = max_happy[n + 2 - i];
		}else{
			max_happy[n + 1 - i] = max(max_happy[n + 2 - i], happy[n + 1 - i]);
		}
		if(fatigue[n + 1 - i] == 0){
			min_fatigue[n + 1 - i] = min_fatigue[n + 2 - i];
		}else{
			min_fatigue[n + 1 - i] = min(min_fatigue[n + 2 - i], fatigue[n + 1 - i]);
		}
		if(fatigue[i] == 0){
			max_fatigue[i] = max_fatigue[i - 1];
		}else{
			max_fatigue[i] = max(max_fatigue[i - 1], fatigue[i]);
		}
	}
	
	int answer = -1;
	for(int i = 1; i <= n - 1; i++){
		if(min_happy[i] > max_happy[i + 1] and max_fatigue[i] < min_fatigue[i + 1]){
			answer = i;
		}
	}
	
	cout << answer;
	
	return 0;
}