#include <iostream>
#include <vector>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> city(n);

    for(auto& x : city){
        cin >> x;
    }

    vector<string> answer(city);

    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            if(city[r][c] == 'O'){
                for(int k = 0; k < 4; k++){
                    int next_r = r + dr[k];
                    int next_c = c + dc[k];
                    while(next_r >= 0 and next_r < n and next_c >= 0 and next_c < n and city[next_r][next_c] == '.'){
                        answer[next_r][next_c] = 'S';
                        next_r += dr[k];
                        next_c += dc[k];
                    }
                }

            }
        }
    }

    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            if(answer[r][c] == 'S'){
                answer[r][c] = '.';
            }else if(answer[r][c] == '.'){
                answer[r][c] = 'B';
            }
        }
    }

    for(auto& x : answer){
        cout << x << "\n";
    }

    return 0;
}