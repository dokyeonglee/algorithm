#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void face_rotate(vector<string>& cube, int face_number, int dir){
    string temp(9, 'x');
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(dir == 1){
                temp[3 * i + j] = cube[face_number][(2 - j) * 3 + i];
            }else{
                temp[3 * i + j] = cube[face_number][3 * j + 2 - i];
            }
        }
    }
    cube[face_number] = temp;
}

void cube_rotate(vector<string>& cube, int rotate_face, vector<int>& turn_face, vector<int>& turn_block_number, int dir){

    face_rotate(cube, rotate_face, dir);

    string temp(3, 'x');
    temp[0] = cube[turn_face[3]][turn_block_number[3] / 100];
    temp[1] = cube[turn_face[3]][turn_block_number[3] / 10 % 10];
    temp[2] = cube[turn_face[3]][turn_block_number[3] % 10];

    for(int i = 3; i > 0 and i < 6; i -= dir){
        cube[turn_face[i % 4]][turn_block_number[i % 4] / 100] = cube[turn_face[(i - dir) % 4]][turn_block_number[(i - dir) % 4] / 100];
        cube[turn_face[i % 4]][turn_block_number[i % 4] / 10 % 10] = cube[turn_face[(i - dir) % 4]][turn_block_number[(i - dir) % 4] / 10 % 10];
        cube[turn_face[i % 4]][turn_block_number[i % 4] % 10] = cube[turn_face[(i - dir) % 4]][turn_block_number[(i - dir) % 4] % 10];
    }
    
    cube[turn_face[(3 + dir) % 4]][turn_block_number[(3 + dir) % 4] / 100] = temp[0];
    cube[turn_face[(3 + dir) % 4]][turn_block_number[(3 + dir) % 4] / 10 % 10] = temp[1];
    cube[turn_face[(3 + dir) % 4]][turn_block_number[(3 + dir) % 4] % 10] = temp[2];

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string color = "wgrboy";
    string face_name = "UDFBLR";

    vector<int> rotate_faces = {0, 5, 2, 4, 1, 3};
    vector<vector<int>> turn_faces = {{4, 3, 2, 1}, {1, 2, 3, 4}, {0, 3, 5, 1}, {1, 5, 3, 0}, {0, 2, 5, 4}, {0, 4, 5, 2}};
    vector<vector<int>> turn_block_numbers = {{12, 12, 12, 12}, {678, 678, 678, 678}, {678, 36, 210, 852}, {36, 678, 852, 210}, {36, 36, 36, 852}, {258, 630, 258, 258}};
    
    int t;
    cin >> t;

    while(t--){

        vector<string> cube(6);
        for(int i = 0; i < 6; i++){
            cube[i] = string(9, color[i]);
        }

        int n;
        cin >> n;

        for(int i = 0; i < n; i++){

            string command;
            cin >> command;
            
            int dir = (command[1] == '+' ? 1 : -1);

            for(int j = 0; j < face_name.size(); j++){
                if(face_name[j] == command[0]){
                    cube_rotate(cube, rotate_faces[j], turn_faces[j], turn_block_numbers[j], dir);
                }
            }

        }
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout << cube[0][3 * i + j];
            }
            cout << "\n";
        }

    }

    return 0;
}