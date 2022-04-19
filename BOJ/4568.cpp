#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	
	while(1){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		vector<char> cache;
		string str;
		cin >> str;
		
		cout << "Simulation " << t << "\n";
		
		for(int i = 0; i < str.size(); i++){
			if(str[i] == '!'){
				for(int j = cache.size() - 1; j >= 0; j--){
					cout << cache[j];
				}
				cout << "\n";
			}else{
				auto it = find(cache.begin(), cache.end(), str[i]);
				if(it != cache.end()){
					cache.erase(it);
					cache.insert(cache.begin(), str[i]);
				}else{
					if(cache.size() >= n){
						cache.pop_back();
					}
					cache.insert(cache.begin(), str[i]);
				}
			}
		}
		
		t++;
		
	}
	
	return 0;
}