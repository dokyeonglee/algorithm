#include <iostream>
#include <vector>

using namespace std;

int get_angle(int n, int a, int b){
    return min((n + a - b) % n, (n + b - a) % n);   
}

bool possible(int n, vector<int>& temp){
	int max_angle = 0;
	int sum  = 0;
	for(int i = 0; i < temp.size(); i++){
        int angle = get_angle(n, temp[i], temp[(i + 1) % temp.size()]);
		sum += angle;
		max_angle = max(max_angle, angle);
	}
	return sum == n and 2 * max_angle != n;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(1){
		
		int t;
		cin >> t;
		
		if(t == 0){
			break;
		}
		
		vector<int> arr(t);
		int left = 0;
		int right = 0;
		
		for(int i = 0; i < t; i++){
			cin >> arr[i];
			right = max(right, arr[i]);
		}
		
		int answer = 1e9;
		
		while(left <= right){
			int mid = (left + right) / 2;
			int sum = 0;
			vector<int> temp;
			for(int i = 0; i < t; i++){
				if(arr[i] >= mid){
					sum += arr[i] - mid;
					temp.push_back(i);
				}
			}
			
			if(possible(t, temp)){
				answer = sum;
				left = mid + 1;
			}else{
				right = mid - 1;
			}
			
		}
		
		cout << answer << "\n\n";
		
	}
	
	return 0;
}