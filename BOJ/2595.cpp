#include <iostream>
#include <queue>

using namespace std;

string solve(int n, int d){
	string result = "";
	int remain = d % n;
	for(int i = 0; i < n + 1; i++){
		result = result + to_string(d);
		if(remain == 0){
			return result;
		}
		remain = (remain * 10 + d) % n;
	}
	return "";
}

string solve(int n, int d1, int d2){
	
	string result = "";
	vector<bool> visited(n);
	queue<pair<string, int>> q;
	
	if(d1 != 0){
		q.push(make_pair(to_string(d1), d1 % n));
		visited[d1 % n] = true;
	}
	
	q.push(make_pair(to_string(d2), d2 % n));
	visited[d2 % n] = true;
	
	while(!q.empty()){
		string num = q.front().first;
		int remain = q.front().second;
		q.pop();
		if(remain == 0){
			return num;
		}
		int next = (remain * 10 + d1) % n;
		
		if(!visited[next]){
			q.push(make_pair(num + to_string(d1), next));
			visited[next] = true;
		}
		
		next = (remain * 10 + d2) % n;
		if(!visited[next]){
			q.push(make_pair(num + to_string(d2), next));
			visited[next] = true;
		}
	}
	
	return "";
}

int main() {
	
	int n;
	cin >> n;
	
	string answer = "";
	int cnt = 987654321;
	
	for(int i = 1; i <= 9; i++){
		string result = solve(n, i);
		if(result.empty()){
			continue;
		}
		if(answer.empty() or answer.size() > result.size()){
			answer = result;
		}else if(answer.size() == result.size()){
			answer = min(answer, result);
		}
	}
	
	if(answer.empty()){
		for(int i = 0; i <= 9; i++){
			for(int j = i + 1; j <= 9; j++){
				string result = solve(n, i, j);
				if(result.empty()){
					continue;
				}
				if(answer.empty() or answer.size() > result.size()){
					answer = result;
				}else if(answer.size() == result.size()){
					answer = min(answer, result);
				}
			}
		}
	}
	cout << answer;
	
	return 0;
}