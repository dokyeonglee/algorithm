#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> cnt(10);

bool check(int v, int a, int b){
	
	while(v){
		cnt[v % 10]++;
		v /= 10;
	}
	while(a){
		cnt[a % 10]--;
		a /= 10;
	}
	while(b){
		cnt[b % 10]--;
		b /= 10;
	}
	
	for(int i = 0; i < 10; i++){
		if(cnt[i]){
			return false;
		}
	}
	
	return true;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> arr;
	arr.reserve(2200);
	
	for(int i = 2; i <= 1000255; i++){
		for(long long j = i + 1; i * j <= 1000255; j++){
			if(check(i * j, i, j)){
				arr.push_back(i * j);
			}else{
				fill(cnt.begin(), cnt.end(), 0);
			}
		}
	}
	
	sort(arr.begin(), arr.end());
	
	while(1){
		int x;
		cin >> x;
		if(x == 0){
			break;
		}
		cout << *lower_bound(arr.begin(), arr.end(), x) << "\n";
	}
	
	return 0;
}