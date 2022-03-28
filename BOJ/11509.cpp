#include <iostream>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int h;
	cin >> h;
	
	h--;
	
	int cnt[1000001] = {0};
	cnt[h]++;
		
	int answer = 1;
	
	for(int i = 0; i < n - 1; i++){
		int x;
		cin >> x;
		if(cnt[x]){
			cnt[x--]--;
			cnt[x]++;
		}else{
			answer++;
			cnt[x - 1]++;
		}
	}
	
	cout << answer;
	
	return 0;
}