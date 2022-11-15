#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int find_parent(vector<int>& parent, int x){
	if(parent[x] == x){
		return x;
	}
	return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, int x, int y){
	x = find_parent(parent, x);
	y = find_parent(parent, y);
	parent[y] = x;
}

bool check(pair<pair<double, double>, pair<double, double>>& a, pair<double, double>& p){
    if(!(p.first >= a.first.first and p.first <= a.second.first and p.second >= min(a.first.second, a.second.second) and p.second <= max(a.first.second, a.second.second))){
        return false;
    }
    return fabs((a.first.second - a.second.second) * (p.first - a.first.first) - (p.second - a.first.second) * (a.first.first - a.second.first)) < 1e-3;
}

bool check(pair<pair<double, double>, pair<double, double>>& a, pair<pair<double, double>, pair<double, double>>& b){
	return fabs((a.first.first - a.second.first) * (b.first.second - b.second.second) - (a.first.second - a.second.second) * (b.first.first - b.second.first)) < 1e-3
        and ((check(b, a.second) and check(a, b.first)) or (check(a, b.second) and check(b, a.first)) or (check(a, b.first) and check(a, b.second)) or (check(b, a.first) and check(b, a.second)));
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> parent(n);
	for(int i = 0; i < n; i++){
		parent[i] = i;
	}
	
	vector<pair<pair<double, double>, pair<double, double>>> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second.first >> arr[i].second.second;
		if(arr[i].first > arr[i].second){
			swap(arr[i].first, arr[i].second);
		}
		for(int j = 0; j < i; j++){
			if(find_parent(parent, j) == j and check(arr[i], arr[j])){
				union_parent(parent, j, i);
                arr[i].first = min(arr[i].first, arr[j].first);
                arr[i].second = max(arr[i].second, arr[j].second);
                arr[j].first = arr[i].first;
                arr[j].second = arr[i].second;
			}	
		}
	}
	
	int answer = 0;
	for(int i = 0; i < n; i++){
		if(find_parent(parent, i) == i){
			answer++;
		}
	}
	
	cout << answer;

	return 0;
}