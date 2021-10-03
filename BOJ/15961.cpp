#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, d, k, c;
	cin >> n >> d >> k >> c;
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	vector<int> cnt(d + 1);
	
	cnt[c]++;
	
	int size = 1;
	
	for(int i = 0; i < k; i++){
		if(cnt[arr[i]]++ == 0){
			size++;
		}
	}
	
	int answer = size;
	
	for(int i = 1; i < n; i++){
		if(++cnt[arr[(i + k - 1) % n]] == 1){
			size++;
		}
		if(--cnt[arr[i - 1]] == 0){
			size--;
		}
		answer = max(answer, size);
	}
	
	cout << answer;
	
	return 0;
}