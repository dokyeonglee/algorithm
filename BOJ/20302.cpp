#include <iostream>
#include <vector>

using namespace std;

void cal(vector<int>& arr, int x, int a){
	x = abs(x);
	for(int i = 2; i * i <= x; i++){
		while(x % i == 0){
			arr[i] += a;
			x /= i;
		}
	}
	if(x > 1){
		arr[x] += a;
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> a(100001);

	int x;
	cin >> x;
	
	if(x == 0){
		cout << "mint chocolate";
		return 0;
	}
	
	cal(a, x, 1);
	
	for(int i = 0; i < n - 1; i++){
		char c;
		int x;
		cin >> c >> x;
		if(x == 0){
			cout << "mint chocolate";
			return 0;
		}
		if(c == '*'){
			cal(a, x, 1);
		}else{
			cal(a, x, -1);
		}
	}
	
	for(int i = 2; i <= 100000; i++){
		if(a[i] < 0){
			cout << "toothpaste";
			return 0;
		}
	}
	cout << "mint chocolate";
	
	return 0;
}