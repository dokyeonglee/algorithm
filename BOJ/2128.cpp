#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, d, k;
	cin >> n >> d >> k;
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		for(int j = 0; j < x; j++){
			int y;
			cin >> y;
			arr[i] |= 1 << --y;
		}
	}
	
	int answer = 0;
	for(int i = 0; i < (1 << d); i++){
		if(__builtin_popcount(i) <= k){
			int solve = 0;
			int student_cnt = 0;
			for(int j = 0; j < n; j++){
				if((i & arr[j]) == arr[j]){
					solve |= arr[j];
					student_cnt++;
				}
			}
			if(solve == i){
				answer = max(answer, student_cnt);
			}
		}
	}
	
	cout << answer;
	
	return 0;
}