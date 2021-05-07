#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

long long cal(long long a, long long b, char op){
	switch(op){
		case '+':
			return a + b;
		case '-':
			return b - a;
		case '*':
			return a * b;
	}
}

long long cal(string& str, vector<int>& priority){
	
	stack<long long> num;
	stack<int> op;
	
	for(int i = 0; i < str.size(); i++){
		
		if(str[i] == '+' or str[i] == '-' or str[i] == '*'){
			
			while(!op.empty() and priority[i / 2] <= priority[op.top() / 2]){
				
				long long a = num.top();
				num.pop();
				
				long long b = num.top();
				num.pop();
				
				num.push(cal(a, b, str[op.top()]));
				op.pop();
				
			}
			
			op.push(i);
			
		}else{
			num.push(str[i] - '0');
		}
	}
	
	while(!op.empty()){
		
		long long a = num.top();
		num.pop();
				
		long long b = num.top();
		num.pop();
				
		num.push(cal(a, b, str[op.top()]));
		op.pop();
	}
	
	return num.top();
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	string str;
	cin >> str;
	
	vector<int> priority(n / 2);
	
	long long answer = INT_MIN;
	
	for(int i = 0; i < (1 << (n / 2)); i++){

		if((i & (i << 1)) == 0){
			
			for(int j = 0; j < n / 2; j++){
				if(i & (1 << j)){
					priority[j] = 1;
				}else{
					priority[j] = 0;
				}
			}
			
			answer = max(answer, cal(str, priority));
			
		}
	}
	
	cout << answer;
	
	return 0;
}