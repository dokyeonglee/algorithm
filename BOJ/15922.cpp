#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<int, int>> line(n);
	for(int i = 0; i < n; i++){
		cin >> line[i].first >> line[i].second;	
	}
	
	int answer = 0;
	int left = -1987654321;
	int right = left;
	
	for(int i = 0; i < n; i++){
		if(right < line[i].first){
			answer += right - left;
			right = line[i].second;
			left = line[i].first;
		}else{
			right = max(right, line[i].second);
		}
	}
	
	cout << answer + right - left;
	
	return 0;
}