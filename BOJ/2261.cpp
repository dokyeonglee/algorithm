#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b){
	return a.second < b.second;
}

int dist_square(pair<int, int>& a, pair<int, int>& b){
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int closest(vector<pair<int, int>>& arr, int left, int right){
	
	if(left == right){
		return 1987654321;
	}
	
	if(right - left == 1){
		return dist_square(arr[left], arr[right]);
	}
	
	if(right - left == 2){
		int dist1 = dist_square(arr[left], arr[left + 1]);
		int dist2 = dist_square(arr[left], arr[right]);
		int dist3 = dist_square(arr[left + 1], arr[right]);
		return min(dist1, min(dist2, dist3));
	}
	
	int mid = (left + right) / 2;
	
	int result = min(closest(arr, left, mid), closest(arr, mid, right));
	
	vector<pair<int, int>> cand;
	for(int i = left; i <= right; i++){
		if((arr[mid].first - arr[i].first) * (arr[mid].first - arr[i].first) < result){
			cand.push_back(arr[i]);
		}
	}
	
	sort(cand.begin(), cand.end(), compare);
	for(int i = 0; i < cand.size(); i++){
		for(int j = i + 1; j < cand.size(); j++){
			if((cand[i].second - cand[j].second) * (cand[i].second - cand[j].second) < result){
				result = min(result, dist_square(cand[i], cand[j]));
			}else{
				break;
			}
		}
	}
	
	return result;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<int, int>> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i].first >> arr[i].second;
	}
	
	sort(arr.begin(), arr.end());
	
	cout << closest(arr, 0, n - 1);
	
	return 0;
}