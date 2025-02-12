#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<bitset<3000>> arr(n);

    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < m; j++){
            arr[i][j] = str[j] - '0';
        }
    }

    for(int i = 0; i < n; i++){
        if(arr[i][0] == 1){
            arr[i].flip();
        }
    }

    vector<int> col(m);

    int c = -1;
    int d = 0;

    for(int j = 0; j < m; j++){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(arr[i][j] == 1){
                col[j]++;
                cnt++;
            }
        }
        if(cnt > d){
            c = j;
            d = cnt;
        }
    }

    if(d == 0){
        cout << n + 1;
    }else if(d > 2){
        cout << 0;
    }else{
        int answer = d % 2;
        for(int i = 0; i < n; i++){
            if(arr[i][c] == 1){
                bool check = true;
                for(int j = 0; j < m; j++){
                    if(j == c){
                        continue;
                    }
                    if(arr[i][j] != 1 and col[j] != 0){
                        check = false;
                        break;
                    }
                }
                answer += check;
            }
        }
        cout << answer;
    }

    return 0;

}