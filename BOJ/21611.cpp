#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dr[] = {0, -1, 1, 0, 0};
int dc[] = {0, 0, 0, -1, 1};

void destroy(vector<vector<int>>& arr, int d, int s){
    int n = arr.size();
    for(int i = 1; i <= s; i++){
        arr[n / 2 + i * dr[d]][n / 2 + i * dc[d]] = 0;
    }
}

void move(vector<vector<int>>& arr, vector<int>& snail){
    int n = arr.size() - 1;
    vector<int> temp;
    for(int i = 0; i < snail.size(); i++){
        if(arr[snail[i] / n + 1][snail[i] % n + 1]){
            temp.push_back(arr[snail[i] / n + 1][snail[i] % n + 1]);
        }
    }
    int idx = 0;
    while(idx < temp.size()){
        int r = snail[idx] / n + 1;
        int c = snail[idx] % n + 1;
        arr[r][c] = temp[idx++];
    }
    while(idx < snail.size()){
        int r = snail[idx] / n + 1;
        int c = snail[idx++] % n + 1;
        arr[r][c] = 0;
    }
}

int explode(vector<vector<int>>& arr, vector<int>& snail){
    int n = arr.size() - 1;
    int result = 0;
    int cnt = 0;
    int now = 0;
    for(int i = 0; i < snail.size(); i++){
        int r = snail[i] / n + 1;
        int c = snail[i] % n + 1;
        if(arr[r][c] == now){
            cnt++;
        }else{
            if(cnt >= 4){
                for(int j = 0; j < cnt; j++){
                    arr[snail[i - j - 1] / n + 1][snail[i - j - 1] % n + 1] = 0;
                }
                result += now * cnt;
            }
            now = arr[r][c];
            cnt = 1;
        }
    }
    if(cnt >= 4){
        for(int j = 0; j < cnt; j++){
            arr[snail[snail.size() - 1 - j] / n + 1][snail[snail.size() - 1 - j] % n + 1] = 0;
        }
        result += now * cnt;
    }

    return result;
}

void change(vector<vector<int>>& arr, vector<int>& snail){
    int n = arr.size() - 1;
    int cnt = 1;
    int now = arr[snail[1] / n + 1][snail[1] % n + 1];
    vector<int> temp(1, 4);
    for(int i = 2; i < snail.size(); i++){
        int r = snail[i] / n + 1;
        int c = snail[i] % n + 1;
        if(arr[r][c] == now){
            cnt++;
        }else{
            if(now){
                temp.push_back(cnt);
                temp.push_back(now);
            }
            now = arr[r][c];
            cnt = 1;
        }
    }

    if(now){
        temp.push_back(cnt);
        temp.push_back(now);
    }

    for(int i = 0; i < min(snail.size(), temp.size()); i++){
        int r = snail[i] / n + 1;
        int c = snail[i] % n + 1;
        arr[r][c] = temp[i];
    }

    for(int i = temp.size(); i < snail.size(); i++){
        int r = snail[i] / n + 1;
        int c = snail[i] % n + 1;
        arr[r][c] = 0;
    }
    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n + 1, vector<int>(n + 1));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=  n; j++){
            cin >> arr[i][j];
        }
    }

    vector<int> snail;
    int r = 0;
    int c = 0;
    int sign = 1;

    for(int i = 0; i < n; i++){
        snail.push_back(r * n + c);
        c += sign;
    }

    c--;

    for(int i = n - 1; i > 0; i--){
        for(int j = 0; j < i; j++){
            r += sign;
            snail.push_back(r * n + c);
        }
        sign = -sign;
        for(int j = 0; j < i; j++){
            c += sign;
            snail.push_back(r * n + c);
        }
    }

    reverse(snail.begin(), snail.end());

    arr[(n + 1) / 2][(n + 1) / 2] = 4;

    int answer = 0;

    for(int i = 0; i < m; i++){
        int d, s;
        cin >> d >> s;
        destroy(arr, d, s);
        move(arr, snail);
        while(1){
            int result = explode(arr, snail);
            if(result == 0){
                break;
            }
            move(arr, snail);
            answer += result;
        }
        change(arr, snail);
    }

    cout << answer;

    return 0;
}