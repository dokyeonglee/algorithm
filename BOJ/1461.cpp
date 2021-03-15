#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> positive_pos;
	vector<int> negative_pos;
	
	for(int i = 0; i < n; i++){
		
		int num;
		cin >> num;
		
		if(num > 0){
			positive_pos.push_back(num);
		}
		
		if(num < 0){
			negative_pos.push_back(-num);
		}
		
	}
	
	sort(positive_pos.begin(), positive_pos.end());
	sort(negative_pos.begin(), negative_pos.end());
	
	int answer = 0;
	int idx = positive_pos.size() - 1;
	
	while(idx >= 0){
		answer += positive_pos[idx] * 2;
		idx -= m;
	}
	
	idx = negative_pos.size() - 1;
	
	while(idx >= 0){
		answer += negative_pos[idx] * 2;
		idx -= m;
	}
	
	if(positive_pos.size() == 0){
		answer -= negative_pos.back();
	}else if(negative_pos.size() == 0){
		answer -= positive_pos.back();
	}else if(positive_pos.back() < negative_pos.back()){
		answer -= negative_pos.back();
	}else{
		answer -= positive_pos.back();
	}
	
	cout << answer;
	return 0;
}