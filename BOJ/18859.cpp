#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	unordered_map<int, int> mp;
	vector<int> arr(n);
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		mp[arr[i]]++;
	}
	
	sort(arr.begin(), arr.end());
	
	int a0 = arr[0];
	mp[arr[0]]--;
	
	int an = arr[1];
	int x = arr[1] - arr[0];
	
	if(x == 0){
		cout << "No";
		return 0;
	}
	
	int z;
	int cnt = 0;
	
	while(mp[an]){
		cnt++;
		mp[an]--;
		z = an;
		an += x;
	}
	
	int sz = n - 1 - cnt;
	
	if(sz <= 1){
		cout << "Yes";
	}else{
		
		int idx = 2;
		while(mp[arr[idx]] == 0){
			idx++;
		}
		
		an = arr[idx];
		int y = an - a0;
	
		int temp = an;
		
		cnt = 0;
		
		while(mp[temp]){
			cnt++;
			temp += y;
		}
		
		if(cnt == sz){
			cout << "Yes";
			return 0;
		}
			
		mp[z]++;
		sz++;
	
		an = min(an, z);
		y = an - a0;
		cnt = 0;
		
		while(mp[an]){
			cnt++;
			an += y;
		}
		
		if(cnt == sz){
			cout << "Yes";
		}else{
			cout << "No";
		}
	}
	
	return 0;
}