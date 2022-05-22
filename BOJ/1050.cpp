#include <iostream>
#include <vector>
#include <sstream>
#include <cstdio>
#include <map>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	map<string, long long> cost;
	for(int i = 0; i < n; i++){
		string str;
		long long c;
		cin >> str >> c;
		cost[str] = c;
	}
	
	map<string, vector<vector<pair<int, string>>>> ex;
	
	for(int i = 0; i < m; i++){
		string str;
		cin >> str;
		stringstream ss(str);
		string name;
		getline(ss, name, '=');
		string ingredient;
		vector<pair<int, string>> temp;
		while(getline(ss, ingredient, '+')){
			temp.push_back(make_pair(ingredient[0] - '0', ingredient.substr(1)));		
		}
		ex[name].push_back(temp);
	}
	
	while(1){
		bool check = false;
		for(auto it : ex){
			for(auto v : it.second){
				long long result = 0;
				for(auto& [cnt, ingredient] : v){
					if(cost.count(ingredient) == 0){
						result = -1;
						break;
					}
					result += cnt * cost[ingredient];
					if(result > 1e9){
						result = 1e9 + 1;
					}
				}
				if(result == -1){
					continue;
				}
				if(cost.count(it.first) and cost[it.first] <= result){
					continue;
				}
				cost[it.first] = result;
				check = true;
			}
		}
		if(!check){
			break;
		}
	}
	
	if(cost.count("LOVE") == 0){
		cout << -1;	
	}else{
		cout << cost["LOVE"];
	}
	
	return 0;
}