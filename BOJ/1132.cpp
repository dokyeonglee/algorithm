#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<long long> cnt(10);
	vector<bool> non_zero(10, false);
	
	for(int i = 0; i < n; i++){
		string num;
		cin >> num;
		non_zero[num[0] - 'A'] = true;
		long long temp = 1;
		for(int j = num.size() - 1; j >= 0; j--){
			cnt[num[j] - 'A'] += temp;
			temp *= 10;
		}
	}
	
	int idx = 0;
	
	for(int i = 0; i < 10; i++){
		if(!non_zero[i]){
			idx = i;
			break;
		}
	}
	
	for(int i = 0; i < 10; i++){
		if(!non_zero[i] and cnt[i] < cnt[idx]){
			idx = i;
		}
	}
	
	cnt[idx] = 0;
	
	sort(cnt.begin(), cnt.end(), greater<long long>());
	
	long long answer = 0;
	
	for(int i = 0; i < 10; i++){
		answer += (9 - i) * cnt[i];
	}
	
	cout << answer;
	
	return 0;
}