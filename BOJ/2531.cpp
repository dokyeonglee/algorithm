#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, d, k, coupon;
	cin >> n >> d >> k >> coupon;
	
	vector<int> sushi(n + k + 1);
	for(int i = 0; i < n; i++){
		cin >> sushi[i];
	}
	
	int number_of_kinds_of_sushi = 1;
	vector<int> cnt(d + 1);
	cnt[coupon] = 1;
	for(int i = 0; i < k; i++){
		if(cnt[sushi[i]] == 0){
			number_of_kinds_of_sushi++;
		}
		cnt[sushi[i]]++;
		
		sushi[n + i] = sushi[i];
	}
	
	int answer = 0;
	for(int i = 0; i < n; i++){
		answer = max(answer, number_of_kinds_of_sushi);
		
		cnt[sushi[i]]--;
		if(cnt[sushi[i]] == 0){
			number_of_kinds_of_sushi--;
		}
		
		if(cnt[sushi[i + k]] == 0){
			number_of_kinds_of_sushi++;
		}
		cnt[sushi[i + k]]++;
	}
	
	cout << answer << endl;
	
	return 0;
}