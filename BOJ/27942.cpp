#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> arr(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> col_psum(n + 1, vector<int>(n + 1));
    vector<vector<int>> row_psum(n + 1, vector<int>(n + 1));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            row_psum[i][j] += row_psum[i][j - 1] + arr[i][j];
            col_psum[j][i] += col_psum[j][i - 1] + arr[i][j];
        }
    }

    string answer = "";
    int total = 0;

    pair<int, int> left_up = make_pair(n / 2, n / 2);
    int width = 2;
    int height = 2;

    while(width <= n or height <= n){

        int sum = 0;
        char dir = '0';
        pair<int, int> next = left_up;

        if(left_up.first > 1){
            int temp = row_psum[left_up.first - 1][left_up.second + width - 1] - row_psum[left_up.first - 1][left_up.second - 1];
            if(sum < temp){
                sum = temp;
                dir = 'U';
            }
        }

        if(left_up.first + height <= n){
            int temp = row_psum[left_up.first + height][left_up.second + width - 1] - row_psum[left_up.first + height][left_up.second - 1];
            if(sum < temp){
                sum = temp;
                dir = 'D';
            }
        }

        if(left_up.second > 1){
            int temp = col_psum[left_up.second - 1][left_up.first + height - 1] - col_psum[left_up.second - 1][left_up.first - 1];
            if(sum < temp){
                sum = temp;
                dir = 'L';
            }
        }

        if(left_up.second + width <= n){
            int temp = col_psum[left_up.second + width][left_up.first + height - 1] - col_psum[left_up.second + width][left_up.first - 1];
            if(sum < temp){
                sum = temp;
                dir = 'R';
            }
        } 

        if(sum > 0){
            total += sum;
            answer += dir;
            if(dir == 'U'){
                left_up.first--;
            }
            if(dir == 'L'){
                left_up.second--;
            }
            if(dir == 'U' or dir == 'D'){
                height++;
            }else{
                width++;
            }
        }else{
            break;
        }

    }

    cout << total << "\n" << answer;

    return 0;
}