#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int a, b;
		cin >> a >> b;
		cout << a / b << ".";
		vector<int> arr(10245, -1);
		int cnt = 0;
		int s = 0;
		int e = 0;
		int temp = a % b * 10;
		while(1){
			a = a % b * 10;
			int& ret = arr[a];
			if(ret != -1){
				s = arr[a];
				e = cnt;
				break;
			}
			ret = cnt++;
		}
		for(int i = 0; i < s; i++){
			cout << temp / b;
			temp = temp % b * 10;
		}
		cout << "(";
		for(int i = s; i < e; i++){
			cout << temp / b;
			temp = temp % b * 10;
		}
		cout << ")\n";
	}
	
	return 0;
}