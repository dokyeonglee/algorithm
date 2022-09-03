#include <iostream>
#include <queue>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	priority_queue<int> pq;
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		pq.push(-x);
	}
	
	if(n == 1){
		cout << "N";
		return 0;
	}
	
	int cnt = 0;
	
	while(pq.size() >= 2){
		int f = pq.top();
		pq.pop();
		int s = pq.top();
		pq.pop();
		if(f == s){
			pq.push(f - 1);
		}else{
			cnt++;
			pq.push(s);
		}
	}
	
	if(cnt <= 1){
		cout << "Y";
	}else{
		cout << "N";
	}
	
	return 0;
}