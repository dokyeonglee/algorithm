#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
	cin.tie(0);

	int r, c, k;
	cin >> r >> c >> k;
	r--;
	c--;

	vector<vector<int>> arr(101, vector<int>(101));
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cin >> arr[i][j];
		}
	}

	int answer = 0;
	int row = 3;
	int col = 3;

	while(answer <= 100 and arr[r][c] != k){

		if(row >= col){
	
			for(int i = 0; i < row; i++){
				vector<int> temp;
				vector<int> cnt(101);
				vector<pair<int, int>> v;
				for(int j = 0; j < col; j++){
					if(arr[i][j] != 0){
						cnt[arr[i][j]]++;
					}
				}

				for(int j = 1; j < 101; j++){
					if(cnt[j] != 0){
						v.push_back(make_pair(cnt[j], j));
					}
				}

				sort(v.begin(), v.end());

				for(int j = 0; j < v.size(); j++){
					temp.push_back(v[j].second);
					temp.push_back(v[j].first);
				}

				col = max(col, (int)temp.size());

				for(int j = 0; j < 101; j++){
                    arr[i][j] = 0;  
                }

				for(int j = 0; j < temp.size(); j++){
					arr[i][j] = temp[j];
				}		

			}

		}else{

			for(int i = 0; i < col; i++){

				vector<int> temp;
				vector<int> cnt(101);
				vector<pair<int, int>> v;

				for(int j = 0; j < row; j++){
					if(arr[j][i] != 0){
						cnt[arr[j][i]]++;
					}
				}

				for(int j = 1; j < 101; j++){
					if(cnt[j] != 0){
						v.push_back(make_pair(cnt[j], j));
					}
				}

				sort(v.begin(), v.end());

				for(int j = 0; j < v.size(); j++){
					temp.push_back(v[j].second);
					temp.push_back(v[j].first);
				}

				row = max(row, (int)temp.size());

				for(int j = 0; j < 101; j++){
                    arr[j][i] = 0;   
                }

				for(int j = 0; j < temp.size(); j++){
					arr[j][i] = temp[j];
				}

			}
		}
		answer++;
	}

	if(answer > 100){
		answer = -1;
	}

	cout << answer;

	return 0;
}