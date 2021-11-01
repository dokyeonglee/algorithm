#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<int, int>> job(n);
	for(int i = 0; i < n; i++){
		cin >> job[i].second >> job[i].first;
		job[i].first *= -1;
	}
	
	sort(job.begin(), job.end());
	
	int answer = 0;
	vector<bool> check(1001, false);
	
	for(int i = 0; i < n; i++){
		for(int j = min(n, job[i].second) - 1; j >= 0; j--){
			if(!check[j]){
				answer += -job[i].first;
				check[j] = true;
				break;
			}
		}
	}
	
	cout << answer;
	
	return 0;
}