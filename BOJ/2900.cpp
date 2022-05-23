#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	vector<long long> arr(n + 1);
	vector<long long> cnt(n + 1);
	
	for(int i = 0; i < k; i++){
		int x;
		cin >> x;
		cnt[x]++;
	}
	
	for(int i = 1; i <= n; i++){
		if(cnt[i]){
			int idx = 0;
			while(idx < n){
				arr[idx] += cnt[i];
				idx += i;
			}
		}
	}
	
	vector<long long> psum(n + 1);
	psum[0] = arr[0];
	
	for(int i = 1; i <= n; i++){
		psum[i] = psum[i - 1] + arr[i];
	}
	
	int q;
	cin >> q;
	
	for(int i = 0; i < q; i++){
		int l, r;
		cin >> l >> r;
		if(l == 0){
			cout << psum[r] << "\n";
		}else{
			cout << psum[r] - psum[l - 1] << "\n";
		}
	}
	
	return 0;
}