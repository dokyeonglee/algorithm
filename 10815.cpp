#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool is_in_card(vector<int>& card, int num){
	
	int lo = 0;
	int hi = card.size() - 1;
	
	while(lo <= hi){
		int mid = (lo + hi) / 2;
		if(card[mid] == num){
			return true;
		}else if(card[mid] < num){
			lo = mid + 1;
		}else{
			hi = mid - 1;
		}
	}
	
	return false;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> card(n);
	for(int i = 0; i < n; i++){
		cin >> card[i];
	}
	
	sort(card.begin(), card.end());
	
	int m;
	cin >> m;
	
	for(int i = 0; i < m; i++){
		int num;
		cin >> num;
		if(is_in_card(card, num)){
			cout << 1 << " ";
		}else{
			cout << 0 << " ";	
		}
	}
	
	return 0;
}