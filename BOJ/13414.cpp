#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int k, l;
	cin >> k >> l;
	
	vector<string> waiting_list(l);
	for(int i = 0; i < l; i++){
		cin >> waiting_list[i];
	}
	
	unordered_map<string, int> umap;
	vector<string> answer;
	
	for(int i = l - 1; i >= 0; i--){
		if(umap[waiting_list[i]] == 0){
			umap[waiting_list[i]] = 1;
			answer.push_back(waiting_list[i]);
		}
	}
	
	int size = answer.size();//size_t == unsigned int 
	for(int i = size - 1; i >= size - k and i >= 0; --i){
		cout << answer[i] << '\n';
	}
	
	return 0;
}