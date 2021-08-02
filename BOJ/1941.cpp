#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int next_bit(int bit){
	int least_nonzero = bit & -bit;
	int temp = bit + least_nonzero;
	temp &= -temp;
	temp /= least_nonzero;
	return bit + least_nonzero + (temp >> 1) - 1;
}

pair<int, int> cnt_SY(vector<string>& classroom, int bit){
	
	int cnt_S = 0;
	int cnt_Y = 0;
	
	for(int i = 0; i < 25; i++){
		if(bit & (1 << i)){
			int r = i / 5;
			int c = i % 5;
			if(classroom[r][c] == 'S'){
				cnt_S++;
			}else{
				cnt_Y++;
			}
		}
	}
	
	return make_pair(cnt_S, cnt_Y);
}

bool is_all_connect(int bit){
	
	int start = bit & -bit;
	for(int i = 0; i < 25; i++){
		if(start == (1 << i)){
			start = i;
			break;
		}
	}
	
	queue<int> q;
	q.push(start);
	
	bit &= ~(1 << start);
	
	while(!q.empty()){
		
		int now = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++){
			
			int next_r = now / 5 + dr[i];
			int next_c = now % 5 + dc[i];
			int next = next_r * 5 + next_c;
			
			if(next_r < 0 or next_r >= 5 or next_c < 0 or next_c >= 5){
				continue;
			}
			
			if(bit & (1 << next)){
				q.push(next);
				bit &= ~(1 << next);
			}
		}
		
	}
	
	return bit == 0;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<string> classroom(5);
	
	for(int i = 0; i < 5; i++){
		cin >> classroom[i];
	}
	
	int answer = 0;
	int bit = 0x7F;
	
	while(bit <= (0x1FC0000)){
		pair<int, int> SY = cnt_SY(classroom, bit);
		if(SY.first > SY.second){
			if(is_all_connect(bit)){
				answer++;
			}
		}
		bit = next_bit(bit);
	}
	
	cout << answer;
	
	return 0;
}