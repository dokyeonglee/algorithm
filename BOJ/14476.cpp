#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> arr(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	
	vector<int> gcd_left_to_right(n + 1);
	vector<int> gcd_right_to_left(n + 1);
	
	gcd_left_to_right[1] = arr[1];
	gcd_right_to_left[n] = arr[n];
	
	for(int i = 2; i <= n; i++){
		gcd_left_to_right[i] = gcd(gcd_left_to_right[i - 1], arr[i]);
		gcd_right_to_left[n - i + 1] = gcd(gcd_right_to_left[n - i + 2], arr[n - i + 1]);
	}
	
	int answer_num = -1;
	int answer_gcd = 0;
	
	for(int i = 1;i <= n; i++){
		int temp = gcd(gcd_left_to_right[i - 1], gcd_right_to_left[i + 1]);
		if(temp > answer_gcd && arr[i] % temp != 0){
			answer_gcd = temp;
			answer_num = arr[i];
		}
	}
	
	if(answer_num == -1){
		cout << -1;
	}else{
		cout << answer_gcd << " " << answer_num;	
	}
	
	
	return 0;
}