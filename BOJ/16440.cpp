#include <iostream>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	string str;
	cin >> str;
	
	int strawberry = 0;
	int kiwi = 0;
	
	for(int i = 0; i < n / 2; i++){
		if(str[i] == 's'){
			strawberry++;
		}else{
			kiwi++;
		}
	}
	
	if(strawberry == kiwi){
		cout << 1 << "\n" << n / 2;
	}else{
		for(int i = n / 2; i < n; i++){
			if(str[i] == 's'){
				strawberry++;
			}else{
				kiwi++;
			}
			if(str[i - n / 2] == 's'){
				strawberry--;
			}else{
				kiwi--;
			}
			if(strawberry == kiwi){
				cout << 2 << "\n" << i - n / 2 + 1 << " " << i + 1;
				break;
			}
		}
	}
	
	return 0;
}