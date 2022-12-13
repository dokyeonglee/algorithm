#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<long long> three(1, 0);
	vector<long long> five(1, 0);
	
	int n, w;
	cin >> n >> w;
	
	for(int i = 0; i < n; i++){
		int t, s;
		cin >> t >> s;
		if(t == 3){
			three.push_back(s);
		}else{
			five.push_back(s);
		}
	}
	
	sort(three.begin() + 1, three.end(), greater<>());
	sort(five.begin() + 1, five.end(), greater<>());
	
	for(int i = 1; i < three.size(); i++){
		three[i] += three[i - 1];
	}
	
	for(int i = 1; i < five.size(); i++){
		five[i] += five[i - 1];
	}
	
	int three_amount = min((int)three.size() - 1, w / 3);
	
	long long answer = 0;
	
	for(int i = three_amount; i >= 0; i--){
		int five_amount = min((int)five.size() - 1, (w - 3 * i) / 5);
		answer = max(answer, three[i] + five[five_amount]);
	}
	
	cout << answer;
	
	return 0;
}