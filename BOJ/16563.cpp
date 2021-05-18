#include iostream
#include vector
#include algorithm

using namespace std;

int main() {
	
	ios_basesync_with_stdio(0);
	cin.tie(0);
	
	vectorint prime_factor(5000001);
	
	for(int i = 1; i = 5000000; i++){
		prime_factor[i] = i;	
	}
	
	for(int i = 2; i  i = 5000000; i++){
		if(prime_factor[i] == i){
			for(int j = i  i; j = 5000000; j += i){
				prime_factor[j] = i;
			}
		}	
	}
	
	int n;
	cin  n;
	
	for(int i = 0; i  n; i++){
		
		int x;
		cin  x;
		
		vectorint answer;
		
		while(x  1){
			answer.push_back(prime_factor[x]);
			x = prime_factor[x];
		}
		
		sort(answer.begin(), answer.end());
		
		for(int factor  answer){
			cout  factor   ;
		}
		cout  n;
	}
	
	return 0;
}