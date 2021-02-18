#include <iostream>
#include <unordered_map>

using namespace std;

int parent[200001];
int number_of_friend[200001];

int find(int x){
	if(x == parent[x]){
		return x;
	}
	return parent[x] = find(parent[x]);
}

void merge(int x, int y){
	x = find(x);
	y = find(y);
	if(x != y){
		if(number_of_friend[x] < number_of_friend[y]){
			swap(x, y);
		}
		parent[y] = x;
		number_of_friend[x] += number_of_friend[y];
		number_of_friend[y] = 0;
	}	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	for(int i = 0; i < T; i++){
		
		int F;
		cin >> F;
		
		for(int i = 0; i <= 2 * F; i++){
			parent[i] = i;
			number_of_friend[i] = 1;
		}
		
		unordered_map<string, int> umap;
		int idx = 1;
		
		for(int i = 0; i < F; i++){
			
			string name1, name2;
			cin >> name1 >> name2;
			
			if(umap[name1] == 0){
				umap[name1] = idx++;
			}
			if(umap[name2] == 0){
				umap[name2] = idx++;
			}
			
			int parent1 = find(umap[name1]);
			int parent2 = find(umap[name2]);
			
			if(parent1 != parent2){
				merge(parent1, parent2);
			}
			cout << max(number_of_friend[parent1], number_of_friend[parent2]) << '\n';
		}
	}
	
	return 0;
}