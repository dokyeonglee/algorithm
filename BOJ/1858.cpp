#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<pair<int, int>, int>> arr(n + 1);
	for(int i = 1; i <= n; i++){
		arr[i].second = i;
		cin >> arr[i].first.first >> arr[i].first.second;
	}
	
	sort(arr.begin() + 1, arr.end());
	
	double max_m = 0;
	vector<int> positive;
	vector<int> negative;
	vector<int> indices(n + 1);

	for(int i = 1; i < n; i++){

		auto p1 = arr[i];
		auto p2 = arr[i + 1];

		indices[arr[i].second] = i;
		indices[arr[i + 1].second] = i + 1;

		double m = (double)(p1.first.second - p2.first.second) / (p1.first.first - p2.first.first);

		if(max_m <= fabs(m)){
			if(max_m < fabs(m)){
				positive.clear();
				negative.clear();
				max_m = fabs(m);
			}
			if(m > 0){
				positive.emplace_back(p1.second);
				positive.emplace_back(p2.second);
			}else{
				negative.emplace_back(p1.second);
				negative.emplace_back(p2.second);
			}
		}
	}
	
	sort(positive.begin(), positive.end());
	sort(negative.begin(), negative.end());
	
	pair<int, int> answer = make_pair(n + 1, n + 1);

	for(int& i : positive){
		if(i == positive[0]){
			continue;
		}
		if((double)(arr[indices[i]].first.second - arr[indices[positive[0]]].first.second) / (arr[indices[i]].first.first - arr[indices[positive[0]]].first.first) == max_m){
			answer = make_pair(positive[0], i);
			break;
		}
	}

	for(int& i : negative){
		if(i == negative[0]){
			continue;
		}
		if((double)(arr[indices[i]].first.second - arr[indices[negative[0]]].first.second) / (arr[indices[i]].first.first - arr[indices[negative[0]]].first.first) == -max_m){
			answer = min(answer, make_pair(negative[0], i));
			break;
		}
	}
	
	cout << answer.first << " " << answer.second;
	
	return 0;
}