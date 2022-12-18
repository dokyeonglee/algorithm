#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string, int>& a, pair<string, int>& b){
	return a.first.size() < b.first.size();
}

string solve(vector<pair<string, int>>& arr, int prefix_idx, int suffix_idx){
	
	string prefix = arr[prefix_idx].first;
	string suffix = arr[suffix_idx].first;
	string result = string(arr.size(), '0');
	
	result[arr[prefix_idx].second] = 'P';
	result[arr[suffix_idx].second] = 'S';
	
	for(int i = 0; i < arr.size() - 2; i += 2){
		string str1 = prefix.substr(0, arr[i].first.size());
		string str2 = suffix.substr(suffix.size() - arr[i].first.size());
		if(str1 == arr[i].first and str2 == arr[i + 1].first){
			result[arr[i].second] = 'P';
			result[arr[i + 1].second] = 'S';
		}else if(str1 == arr[i + 1].first and str2 == arr[i].first){
			result[arr[i].second] = 'S';
			result[arr[i + 1].second] = 'P';
		}else{
			result = "";
			break;
		}
	}
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<string, int>> arr(2 * n - 2);
	for(int i = 0; i < 2 * n - 2; i++){
		cin >> arr[i].first;
		arr[i].second = i;
	}
	
	sort(arr.begin(), arr.end(), compare);
	
	string answer2 = solve(arr, arr.size() - 1, arr.size() - 2);
	string answer1 = arr[arr.size() - 1].first + arr[arr.size() - 2].first.back();
	
	if(answer2.size() == 0){
		answer2 = solve(arr, arr.size() - 2, arr.size() - 1);
		answer1 = arr[arr.size() - 2].first + arr[arr.size() - 1].first.back();
	}

	cout << answer1 << "\n";
	cout << answer2;
	
	return 0;
}