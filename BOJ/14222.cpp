#include <iostream>
#include <queue>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	priority_queue<int> pq;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		pq.push(-x);
	}
	
	int answer = 0;
	int now = 1;
	
	while(!pq.empty()){
		int x = -pq.top();
		pq.pop();
		if(x == now){
			now++;
		}else if(x + k <= n){
			pq.push(-(x + k));
		}
	}

	if(now == n + 1){
		cout << 1;
	}else{
		cout << 0;
	}
	
	return 0;
}