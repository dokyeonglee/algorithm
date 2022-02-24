#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<long long, long long>& a, pair<long long, long long>& b){
	return a.first * b.second > a.second * b.first;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<long long, long long>> arr;
	arr.reserve(n + 5);
	
	long long answer = 0;
	long long temp = 0;

	for(int i = 0; i < n; i++){
		long long a, b;
		cin >> a >> b;
		if(a == 0 or b == 0){
			temp += b;
			temp %= 40000;
		}else{
			arr.push_back(make_pair(a, b));
		}
	}
	
	long long curr = 0;
		
	sort(arr.begin(), arr.end(), compare);
	
	for(int i = 0; i < arr.size(); i++){
		answer += answer * arr[i].first + arr[i].second;
		answer %= 40000;
	}
	
	cout << (answer + temp) % 40000;
		
	return 0;
}