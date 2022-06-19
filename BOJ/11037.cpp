#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer;

void combination(string& digit, string comb, int r, int idx, int depth){
	if(r == 0){
		do{
			answer.push_back(stoi(comb));
		}while(next_permutation(comb.begin(), comb.end()));
	}else if(depth != digit.size()){
		comb[idx] = digit[depth];
		combination(digit, comb, r - 1, idx + 1, depth + 1);
		combination(digit, comb, r, idx, depth + 1);
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string digit = "123456789";
	for(int i = 1; i <= 9; i++){
		string comb(i, '0');
		combination(digit, comb, i, 0, 0);
	}
	
	sort(answer.begin(), answer.end());
	
	int n;
	while(cin >> n){
		auto it = lower_bound(answer.begin(), answer.end(), n + 1);
		if(it == answer.end()){
			cout << "0\n";
		}else{
			cout << *it << "\n";
		}
	}
	
	return 0;
}