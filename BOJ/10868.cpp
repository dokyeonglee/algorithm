#include <iostream>
#include <vector>

using namespace std;

int init(vector<int>& tree, vector<int>& arr, int start, int end, int node){
	if(start == end){
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = min(init(tree, arr, start, mid, node * 2), init(tree, arr, mid + 1, end, node * 2 + 1));
}

int query(vector<int>& tree, int start, int end, int node, int left, int right){
	if(left > end or right < start){
		return 1987654321;
	}
	if(left <= start and end <= right){
		return tree[node];
	}
	int mid = (start + end) / 2;
	return min(query(tree, start, mid, node * 2, left, right), query(tree, mid + 1, end, node * 2 + 1, left, right));
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> arr(n);
	vector<int> tree(4 * n);
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	init(tree, arr, 0, n - 1, 1);
	
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		cout << query(tree, 0, n - 1, 1, a - 1, b - 1) << "\n";
	}
	
	return 0;
}