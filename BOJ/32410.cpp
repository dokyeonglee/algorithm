#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<pair<int, int>> arr(n + 1);

    vector<vector<int>> number_of_weapon(601, vector<int>(601, 1e9));

    number_of_weapon[x][y] = 0;

    for(int i = 1; i <= n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    for(int i = 1; i <= n; i++){
        for(int a = 300; a >= x; a--){
            for(int b = 300; b >= y; b--){
                if(number_of_weapon[a][b] != 1e9){
                    number_of_weapon[a + arr[i].first][b + arr[i].second] = min(number_of_weapon[a + arr[i].first][b + arr[i].second], number_of_weapon[a][b] + 1);
                }
            }
        }
    }

    vector<vector<int>> number_of_monster(601, vector<int>(601));

    int k;
    cin >> k;

    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        number_of_monster[a][b]++;
    }

    for(int i = 1; i <= 600; i++){
        for(int j = 1; j <= 600; j++){
            number_of_monster[i][j] += number_of_monster[i - 1][j] + number_of_monster[i][j - 1] - number_of_monster[i - 1][j - 1];
        }
    }

    int answer = 0;

    for(int i = 1; i <= 600; i++){
        for(int j = 1; j <= 600; j++){
            if(number_of_weapon[i][j] <= m){
                answer = max(answer, number_of_monster[i][j]);
            }
        }
    }

    cout << answer;

    return 0;
}