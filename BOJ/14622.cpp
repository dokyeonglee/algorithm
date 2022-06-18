#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> is_prime(5e6 + 1, true);
vector<bool> visited(5e6 + 1, false);

void cal_score(priority_queue<int>& my_pq, priority_queue<int>& your_pq, long long& my_score, long long& your_score, int x){
	if(!is_prime[x]){
		if(your_pq.size() == 3){
			your_score += -your_pq.top();
		}else{
			your_score += 1000;
		}
	}else if(visited[x]){
		my_score -= 1000;
	}else{
		my_pq.push(-x);
		if(my_pq.size() > 3){
			my_pq.pop();
		}
		visited[x] = true;
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	is_prime[0] = is_prime[1] = false;
	for(int i = 2; i * i <= 5e6; i++){
		if(is_prime[i]){
			for(int j = i * i; j <= 5e6; j += i){
				is_prime[j] = false;		
			}
		}
	}
	
	int n;
	cin >> n;
	
	long long dae_score = 0;
	long long gyu_score = 0;
	
	priority_queue<int> dae_pq, gyu_pq;
	
	for(int i = 0; i < n; i++){
		int d, g;
		cin >> d >> g;
		cal_score(dae_pq, gyu_pq, dae_score, gyu_score, d);
		cal_score(gyu_pq, dae_pq, gyu_score, dae_score, g);
	}
	
	if(dae_score > gyu_score){
		cout << "소수의 신 갓대웅";
	}else if(dae_score < gyu_score){
		cout << "소수 마스터 갓규성";
	}else{
		cout << "우열을 가릴 수 없음";
	}
		
	return 0;
}