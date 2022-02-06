#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<pair<int, int>, int>> arr(n);
	for(int i = 0; i < n; i++){
		arr[i].second = i + 1;
		cin >> arr[i].first.first >> arr[i].first.second;
	}
	
	sort(arr.begin(), arr.end());
	
	double max_m = 0;
	vector<int> pos;
	vector<int> neg;
	
	for(int i = 0; i < n - 1; i++){
		auto p1 = arr[i];
		auto p2 = arr[i + 1];
		double m = (double)(p1.first.second - p2.first.second) / (p1.first.first - p2.first.first);
		if(max_m <= abs(m)){
			if(max_m < abs(m)){
				pos.clear();
				neg.clear();
				max_m = abs(m);
			}
			if(m > 0){
				pos.push_back(p1.second);
				pos.push_back(p2.second);
			}else{
				neg.push_back(p1.second);
				neg.push_back(p2.second);
			}
		}
	}
	
	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());
	
	pair<int, int> answer = make_pair(n + 2, n + 2);
	if(pos.size() > 1){
		answer = make_pair(pos[0], pos[1]);
	}
	if(neg.size() > 1){
		answer = min(answer, make_pair(neg[0], neg[1]));
	}
	
	cout << answer.first << " " << answer.second;
	
	return 0;
}