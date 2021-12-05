#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> arr(1001);
	vector<int> brr(1001);
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		arr[x]++;
	}
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		brr[x]++;
	}
	
	int answer = 0;
	
	for(int i = 1; i <= 1000; i++){
		while(arr[i] > 0){
			bool check = false;
			for(int j = i - 1; j >= 1; j--){
				if(brr[j] > 0){
					answer += 2;
					arr[i]--;
					brr[j]--;
					check = true;
					break;
				}
			}
			if(!check){
				break;
			}
		}
	}
	
	for(int i = 1; i <= 1000; i++){
		while(arr[i] > 0 and brr[i] > 0){
			answer += 1;
			arr[i]--;
			brr[i]--;
		}
	}
	
	cout << answer;
	
	return 0;
}