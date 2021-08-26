#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >>  n;
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	int g = abs(arr[1] - arr[0]);
	
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			g = gcd(g, abs(arr[j] - arr[i]));
		}
	}
	
	vector<int> answer;
	
	for(int i = 2; i * i <= g; i++){
		if(g % i == 0){
			answer.push_back(i);
			if(i * i != g){
				answer.push_back(g / i);
			}
		}	
	}
	
	sort(answer.begin(), answer.end());	
	answer.push_back(g);
	
	for(int i = 0; i < answer.size(); i++){
		cout << answer[i] << " ";
	}
	return 0;
}