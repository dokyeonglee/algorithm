#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<string> gears(5);
	vector<int> zero_pos(5);
	for(int i = 1; i <= 4; i++){
		cin >> gears[i];
	}
	
	int k;
	cin >> k;
	
	for(int i = 0; i < k; i++){
		
		int num, dir;
		cin >> num >> dir;
		
		vector<int> temp(zero_pos);
		
		int curr_dir = dir;
		
		for(int j = num + 1; j <= 4; j++){
			
			int left_gear_pole = gears[j - 1][(temp[j - 1] + 2) % 8];
			int right_gear_pole = gears[j][(temp[j] + 6) % 8];
			
			if(left_gear_pole != right_gear_pole){
				zero_pos[j] = (zero_pos[j] + curr_dir + 8) % 8;
			}else{
				break;
			}
			
			curr_dir *= -1;
		}
		
		curr_dir = dir;
		
		for(int j = num - 1; j >= 1; j--){
			
			int left_gear_pole = gears[j][(temp[j] + 2) % 8];
			int right_gear_pole = gears[j + 1][(temp[j + 1] + 6) % 8];
			
			if(left_gear_pole != right_gear_pole){
				zero_pos[j] = (zero_pos[j] + curr_dir + 8) % 8;
			}else{
				break;
			}
			
			curr_dir *= -1;
		}
		
		zero_pos[num] = (zero_pos[num] - dir + 8) % 8;
		
	}
	
	int answer = 0;
	int weight = 1;
	
	for(int i = 1; i <= 4; i++){
		answer += (gears[i][zero_pos[i]] - '0') * weight;
		weight *= 2;
	}
	
	cout << answer << '\n';

	return 0;
}