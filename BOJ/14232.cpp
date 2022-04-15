#include <iostream>
#include <vector>

using namespace std;

int main() {
		
	long long k;
	cin >> k;
	
	vector<long long> answer;
	for(long long i = 2; i * i <= k; i++){
		while(k % i == 0){
			answer.push_back(i);
			k /= i;
		}
	}
	
	if(k > 1){
		answer.push_back(k);
	}
	
	cout << answer.size() << "\n";
	for(long long a : answer){
		cout << a << " ";
	}
	
	return 0;
}