#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	map<char, int> idx;
		
	string charset, encrypted;
	cin >> charset >> encrypted;
	
	long long mod[1000001] = {1};
	int m = 900528;
	
	mod[0] %= m;
	
	for(int i = 1; i <= 1000000; i++){
		mod[i] = (mod[i - 1] * charset.size()) % m;
	}
	
	for(int i = 0; i < charset.size(); i++){
		idx[charset[i]] = i + 1;
	}
	
	long long answer = 0;
	
	for(int i = 0; i < encrypted.size() - 1; i++){
		answer = (answer + 1) * charset.size() % m;
	}
	
	for(int i = 0; i < encrypted.size(); i++){
		answer = (answer + (idx[encrypted[i]] - 1) * mod[encrypted.size() - i - 1]) % m;
	}
	
	cout << (answer + 1) % m;
	
	return 0;
}