#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int vector_gcd(vector<int>& arr){
	int result = arr[0];
	for(int i = 0; i < arr.size(); i++){
		result = gcd(result, arr[i]);
	}
	return gcd(result, 360);
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	int g = vector_gcd(arr);
	
	for(int i = 0; i < k; i++){
		int x;
		cin >> x;
		if(x % g == 0){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}
	
	return 0;
}