#include <iostream>
#include <vector>

using namespace std;

bool finishable(string& row, string& row2, int k){

    int n = row.size();

    for(int i = 0; i < n; i++){
        if(row[i] == '#' and row2[i] == '#'){
            return false;
        }
    }

    for(int i = 0; i < n - 1; i++){
        if((row[i] == '#' and row2[i + 1] == '#') or (row2[i] == '#' and row[i + 1] == '#')){
            return false;
        }
    }

    if(k > 1){
        if((row2.back() == '#' and row.front() == '#') or (row.back() == '#' and row2.front() == '#')){
            return false;
        }
    }

    return true;

}

vector<int> get_obstacle_row(string& row, string& row2){

    int n = row.size();

    vector<int> obstacles;

    for(int i = 0; i < n; i++){
        if(row[i] == '#'){
            obstacles.push_back(0);
        }
        if(row2[i] == '#'){
            obstacles.push_back(1);
        }
    }

    return obstacles;

}

long long change_lane_cnt(vector<int>& obstacles, int k){

    int n = obstacles.size();

    long long result = 0;

    if(n > 0){
        for(int i = 0; i < n - 1; i++){
            if(obstacles[i] != obstacles[i + 1]){
                result += k;
            }
        }
        if(obstacles.front() != obstacles.back()){
            result += k - 1;
        }
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, k;
    cin >> n >> k;


    string row, row2;
    cin >> row >> row2;

    if(!finishable(row, row2, k)){
        cout << -1;
        return 0;
    }

    vector<int> obstacles = get_obstacle_row(row, row2);
    
    long long answer = n * k - 1 + change_lane_cnt(obstacles, k);

    cout << answer;

    return 0;
}