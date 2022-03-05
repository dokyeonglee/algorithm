#include <iostream>
#include <vector>

using namespace std;

long long init(vector<long long>& tree, vector<long long>& arr, int start, int end, int node){
	if(start == end){
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	long long left = init(tree, arr, start, mid, node * 2);
	long long right = init(tree, arr, mid + 1, end, node * 2 + 1);
	return tree[node] = max(left, right);
}

long long max_lux(vector<long long>& tree, int start, int end, int node, int left, int right){
	if(left > end or right < start){
		return -1;
	}
	if(left <= start and end <= right){
		return tree[node];
	}
	int mid = (start + end) / 2;
	int left_max = max_lux(tree, start, mid, node * 2, left, right);
	int right_max = max_lux(tree, mid + 1, end, node * 2 + 1, left, right);
	return max(left_max, right_max);
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<long long> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	vector<long long> tree(arr.size() * 4);
	
	init(tree, arr, 0, arr.size() - 1, 1);
	
	for(int i = m - 1; i < n - m + 1; i++){
		cout << max_lux(tree, 0, n - 1, 1, i - (m - 1), i + m - 1) << " ";
	}
	
	return 0;
}