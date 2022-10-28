#include <iostream>
using namespace std;

int solve(string& src, string& dst){
	int cnt = 0;
	for(int i = 1; i < src.size(); i++){
		if(src[i - 1] != dst[i - 1]){
			src[i - 1] ^= 1;
			src[i] ^= 1;
			if(i != src.size() - 1){
				src[i + 1] ^= 1;
			}
			cnt++;
		}
	}
	if(src == dst){
		return cnt;
	}
	return 987654321;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	string src, dst;
	cin >> src >> dst;
	
	string temp = src;
	
	int answer = solve(src, dst);

	temp[0] ^= 1;
	temp[1] ^= 1;
	
	answer = min(answer, solve(temp, dst) + 1);

	if(answer == 987654321){
		answer = -1;
	}
	
	cout << answer;
	
	
	return 0;
}