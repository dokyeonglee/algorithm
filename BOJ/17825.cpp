#include <iostream>
#include <vector>

using namespace std;

int table[33][6] = {
	{0, 1, 2, 3, 4, 5},
	{2, 2, 3, 4, 5, 9},
	{4, 3, 4, 5, 9, 10},
	{6, 4, 5, 9, 10, 11},
	{8, 5, 9, 10, 11, 12},
	{10, 6, 7, 8, 20, 29},
	{13, 7, 8, 20, 29, 30},
	{16, 8, 20, 29, 30, 31},
	{19, 20, 29, 30, 31, 32},
	{12, 10, 11, 12, 13, 14},
	{14, 11, 12, 13, 14, 15},
	{16, 12, 13, 14, 15, 16},
	{18, 13, 14, 15, 16, 17},
	{20, 18, 19, 20, 29, 30},
	{22,15,16,17,24,25},
	{24,16,17,24,25,26},
	{26,17,24,25,26,27},
	{28,24,25,26,27,28},
	{22,19,20,29,30,31},
	{24,20,29,30,31,32},
	{25,29,30,31,32,32},
	{26,20,29,30,31,32},
	{27,21,20,29,30,31},
	{28,22,21,20,29,30},
	{30,23,22,21,20,29},
	{32,26,27,28,31,32},
	{34,27,28,31,32,32},
	{36,28,31,32,32,32},
	{38,31,32,32,32,32},
	{30,30,31,32,32,32},
	{35,31,32,32,32,32},
	{40,32,32,32,32,32},
	{0,32,32,32,32,32} 
};

const int kBoardSize = 32;

int play(int choice, vector<int>& dice){
	
	vector<int> pos(4);
	vector<int> cnt(40);
	int score = 0;
	
	cnt[0] = 4;
	
	for(int i = 0; i < 10; i++){
		
		int piece = (choice >> (i * 2)) & 0b11;
		
		cnt[pos[piece]]--;
		pos[piece] = table[pos[piece]][dice[i]];
		cnt[pos[piece]]++;
		score += table[pos[piece]][0];
		
		if(cnt[pos[piece]] > 1 and pos[piece] > 0 and pos[piece] != kBoardSize){
			return 0;	
		}
	}
	
	return score;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> dice(10);
	for(int i = 0; i < 10; i++){
		cin >> dice[i];
	}
	
	int answer = 0;
	for(int i = 0; i < (1 << 20); i++){
		answer = max(answer, play(i, dice));
	}
	
	cout << answer;
	
	return 0;
}