#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string big_int_add(string a, string b){
	
	string answer = "";
	
	int a_pos = a.size() - 1;
	int b_pos = b.size() - 1;
	
	int sum = 0;
	
	while(a_pos >= 0 or b_pos >= 0 or sum > 0){
		
		if(a_pos >= 0){
			sum += a[a_pos] - '0';
			a_pos--;
		}
		
		if(b_pos >= 0){
			sum += b[b_pos] - '0';
			b_pos--;
		}
		
		answer.push_back('0' + sum % 10);//better than "answer += '0' + sum % 10"
		sum /= 10;
	}
	
	reverse(answer.begin(), answer.end());
	
	return answer;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<string>> C(n + 1, vector<string>(n + 1));
	
	C[1][0] = "1";
	C[1][1] = "1";
	
	for(int i = 2; i <= n; i++){
		C[i][0] = "1";
		for(int j = 1; j <= i; j++){
			C[i][j] = big_int_add(C[i - 1][j - 1], C[i - 1][j]);	
		}
	}
	
	cout << C[n][m] << endl;
	 
	return 0;
}