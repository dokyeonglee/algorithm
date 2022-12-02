#include <iostream>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long answer = 1;
	long long r = 0;
	long long c = 0;
	
	long long n, k;
	cin >> n >> k;
	
	string path;
	cin >> path;
	
	for(int i = 0; i < path.size(); i++){
		if(path[i] == 'U'){
			r--;
		}else if(path[i] == 'D'){
			r++;
		}else if(path[i] == 'L'){
			c--;
		}else if(path[i] == 'R'){
			c++;
		}
		if(c < n - r){
			if((r + c) % 2 == 0){
				answer += (r + c) * (r + c + 1) / 2 + 1 + c;
			}else{
				answer += (r + c) * (r + c + 1) / 2 + 1 + r;
			}
		}else{
			if((r + c) % 2 == 0){
				answer += n * n - (n - 1 - r + n - 1 - c) * ((n - 1 - r + n - 1 - c) + 1) / 2 - (n - 1 - c);
			}else{
				answer += n * n - (n - 1 - r + n - 1 - c) * ((n - 1 - r + n - 1 - c) + 1) / 2 - (n - 1 - r);
			}
		}
	}
	
	cout << answer;
	
	return 0;
}