#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<vector<int>> rotate(vector<vector<int>>& arr){
	vector<vector<int>> result(arr[0].size(), vector<int>(arr.size()));
	for(int i = 0; i < arr[0].size(); i++){
		for(int j = 0; j < arr.size(); j++){
			result[i][j] = arr[arr.size() - j - 1][i];
		}
	}
	return result;
}

vector<vector<int>> reverse_rotate(vector<vector<int>>& arr){
    vector<vector<int>> result(arr);
    for(int i = 0; i < 3; i++){
        result = rotate(result);
    }
    return result;
}

vector<vector<int>> v_reverse(vector<vector<int>>& arr){
	vector<vector<int>> result(arr);
	for(int i = 0; i < arr.size(); i++){
		for(int j = 0; j < arr[0].size(); j++){
			result[i][j] = arr[arr.size() - i - 1][j];
		}
	}
	return result;
}

vector<vector<int>> h_reverse(vector<vector<int>>& arr){
	for(int i = 0; i < arr.size(); i++){
		reverse(arr[i].begin(), arr[i].end());
	}
    return arr;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, r;
	cin >> n >> m >> r;
	
	vector<vector<int>> _arr(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> _arr[i][j];
		}
	}
	
	vector<vector<vector<int>>> arr(4, vector<vector<int>>(n / 2, vector<int>(m / 2)));
	
	for(int i = 0; i < n / 2; i++){
		for(int j = 0; j < m / 2; j++){
			arr[0][i][j] = _arr[i][j];
		}
	}
	
	for(int i = 0; i < n / 2; i++){
		for(int j = m / 2; j < m; j++){
			arr[1][i][j - m / 2] = _arr[i][j];
		}
	}
	
	for(int i = n / 2; i < n; i++){
		for(int j = 0; j < m / 2; j++){
			arr[2][i - n / 2][j] = _arr[i][j];
		}
	}
	
	for(int i = n / 2; i < n; i++){
		for(int j = m / 2; j < m; j++){
			arr[3][i - n / 2][j - m / 2] = _arr[i][j];
		}
	}
	
	int pos[4] = {0, 1, 2, 3};
	int next_state[9][5] = {{0, 0, 0}, 
                            {1, 2, 3, 4, 5}, {2, 1, 6, 7, 8}, {3, 6, 1, 8, 7}, {4, 8, 7, 6, 1}, 
                            {5, 7, 8, 1, 6}, {6, 3, 2, 5, 4}, {7, 5, 4, 3, 2}, {8, 4, 5, 2, 3} };

    int state = 1;
	for(int i = 0; i < r; i++){

		int x;
		cin >> x;

        if(x < 5){
            state = next_state[state][x];
        }

		if(x == 1){
			swap(pos[0], pos[2]);
			swap(pos[1], pos[3]);
		}else if(x == 2){
			swap(pos[0], pos[1]);
			swap(pos[2], pos[3]);
		}else if(x % 2){
			int temp = pos[3];
			pos[3] = pos[1];
			pos[1] = pos[0];
			pos[0] = pos[2];
			pos[2] = temp;
		}else{
			int temp = pos[3];
			pos[3] = pos[2];
			pos[2] = pos[0];
			pos[0] = pos[1];
			pos[1] = temp;
		}
	}
    
    if(state >= 6){
        for(int i = 0; i < 4; i++){
            arr[i] = v_reverse(arr[i]);
        }
        state -= 3;
    }

    if(state == 2){
        for(int i = 0; i < 4; i++){
            arr[i] = v_reverse(arr[i]);
        }
    }else if(state == 3){
        for(int i = 0; i < 4; i++){
            arr[i] = h_reverse(arr[i]);
        }
    }else if(state == 4){
        for(int i = 0; i < 4; i++){
            arr[i] = rotate(arr[i]);
        }
    }else if(state == 5){
        for(int i = 0; i < 4; i++){
            arr[i] = reverse_rotate(arr[i]);
        }
    }
    	
	vector<vector<int>> answer(arr[0].size() * 2, vector<int>(arr[0][0].size() * 2));
	for(int i = 0; i < 4; i++){
		for(int r = 0; r < arr[i].size(); r++){
			for(int c = 0; c < arr[i][r].size(); c++){
				answer[i / 2 * (answer.size() / 2) + r][i % 2 * (answer[0].size() / 2) + c] = arr[pos[i]][r][c];
			}
		}
	}
	
	for(int i = 0; i < answer.size(); i++){
		for(int j = 0; j < answer[i].size(); j++){
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}