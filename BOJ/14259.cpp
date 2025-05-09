#include <iostream>
#include <vector>

using namespace std;

bool can_avoid_missile(int board_size, int number_of_ships, int ship_size, const vector<int>& missile_positions, int number_of_used_missiles){

    vector<bool> is_hit(board_size + 1);
    for(int i = 0; i < number_of_used_missiles; i++){
        is_hit[missile_positions[i]] = true;
    }

    int last_missile_position = 0;
    int placed_ships_count = 0;

    for(int i = 1; i <= board_size; i++){
        if(is_hit[i]){
            placed_ships_count += (i - last_missile_position) / (ship_size + 1);
            last_missile_position = i;  
        }
    }

    placed_ships_count += (board_size + 1 - last_missile_position) / (ship_size + 1);

    return number_of_ships <= placed_ships_count;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int board_size, number_of_ships, size_of_ship;
    cin >> board_size >> number_of_ships >> size_of_ship;

    int number_of_missiles;
    cin >> number_of_missiles;
    
    vector<int> missile_positions(number_of_missiles);
    for(int i = 0; i < number_of_missiles; i++){
        cin >> missile_positions[i];
    }

    int left = 1;
    int right = number_of_missiles;

    int answer = -1;

    while(left <= right){
        int mid = (left + right) / 2;
        if(can_avoid_missile(board_size, number_of_ships, size_of_ship, missile_positions, mid)){
            left = mid + 1;
        }else{
            answer = mid;
            right = mid - 1;
        }
    }

    cout << answer;

    return 0;

}