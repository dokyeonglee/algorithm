#include <iostream>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string a, b;
	cin >> a >> b;
	
	if(a.size() > b.size()){
		swap(a, b);
	}
	
	int answer = a.size() + b.size();
	
	for(int i = 0; i < a.size(); i++){
		bool check = true;
		for(int j = 0; j <= i; j++){
			if(a[a.size() - 1 - i + j] == '2' and b[j] == '2'){
				check = false;
				break;
			}
		}
		if(check){
			answer = min(answer, (int)a.size() + (int)b.size() - 1 - i);
		}
	}
	
	for(int i = 0; i < a.size(); i++){
		bool check = true;
		for(int j = 0; j <= i; j++){
			if(a[j] == '2' and b[b.size() - 1 - i + j] == '2'){
				check = false;
				break;
			}
		}
		if(check){
			answer = min(answer, (int)a.size() + (int)b.size() - 1 - i);
		}
	}
	
	for(int i = 0; i < b.size() - a.size(); i++){
		bool check = true;
		for(int j = 0; j < a.size(); j++){
			if(a[j] == '2' and b[i + j] == '2'){
				check = false;
				break;
			}
		}
		if(check){
			answer = min(answer, (int)b.size());
		}
	}
	
	cout << answer;
	
	return 0;
}