#include <iostream>
#include <vector>

using namespace std;

vector<int> gray_code(int n){
	vector<int> result;
	for(int i = 0; i < (1 << n); i++){
		result.push_back(i ^ (i >> 1));		
	}
	return result;
}

int main() {
	
	int n;
	cin >> n;
	
	for(int x : gray_code(n)){
		string result = "";
		for(int i = n - 1; i >= 0; i--){
			if(x & (1 << i)){
				result += '1';
			}else{
				result += '0';
			}
		}
		cout << result << "\n";
	}
	
	return 0;
}