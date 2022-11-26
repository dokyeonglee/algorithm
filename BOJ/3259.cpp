#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> arr(n);
	vector<int> brr(n);
	
	for(int i = 0; i < n; i++){
		
		int k;
		cin >> k;
	
		for(int j = 0; j < k; j++){
			int x;
			cin >> x;
			arr[i] |= 1 << --x;
		}
		
		int l;
		cin >> l;
		
		for(int j = 0; j < l; j++){
			int x;
			cin >> x;
			brr[i] |= 1 << --x;
		}
		
	}
	
	for(int i = 0; i < (1 << n); i++){
		bool check = true;
		bool check2 = true;
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				check &= (i & arr[j]) == arr[j] and (~i & brr[j]) == brr[j];
			}else{
				check2 &= (i & arr[j]) != arr[j] or (~i & brr[j]) != brr[j];
			}
		}
		if(check and check2){
			for(int j = 0; j < n; j++){
				if(i & (1 << j)){
					cout << "true\n";
				}else{
					cout << "false\n";
				}
			}
			return 0;
		}
	}
	
	return 0;
}