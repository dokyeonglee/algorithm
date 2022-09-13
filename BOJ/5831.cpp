#include <iostream>
#include <vector>

using namespace std;

int idx;

vector<long long> solve(int bulb, int n){
	
	vector<bool> visited(1 << n);
	visited[bulb] = true;
	
	vector<long long> result;
	result.push_back(bulb);
	
	while(1){
		long long now = result.back();
		long long next = now ^ ((now >> 1) | ((now & 1) << (n - 1)));
		if(visited[next]){
			for(int i = 0; i < result.size(); i++){
				if(result[i] == next){
					idx = i;
					break;
				}
			}
			break;
		}
		visited[next] = true;
		result.push_back(next);
	}
	
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n, b;
	cin >> n >> b;
	

	long long bulb = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		bulb = (bulb << 1) | x;
	}
	
	auto v = solve(bulb, n);
	
	long long answer;
	if(b <= idx){
		answer = v[b];
	}else{
		answer = v[idx + (b - idx) % (v.size() - idx)];
	}
	for(int i = n - 1; i >= 0; i--){
		if(answer & (1 << i)){
			cout << "1\n";
		}else{
			cout << "0\n";
		}
	}

	return 0;
}