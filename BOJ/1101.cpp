#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    int answer = n - 1;

    for(int joker = 0; joker < n; joker++){

        long long visited = 0;
        int result = n - 1;

        for(int i = 0; i < n; i++){

            if(i == joker){
                continue;
            }

            int cnt = 0;
            int color = -1;

            for(int j = 0; j < m; j++){
                if(arr[i][j]){
                    cnt++;
                    color = j;
                }
            }

            if(cnt == 0){
                result--;
            }else if(cnt == 1){
                visited |= (1 << color);
            }

        }

        answer = min(answer, result - __builtin_popcountll(visited));

    }

    cout << answer;

    return 0;
}