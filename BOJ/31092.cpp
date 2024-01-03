#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<char> ch(m);
    vector<int> d(m);
    vector<int> min_a(26, 987654321);

    int a;

    for(int i = 0; i < m; i++){
        cin >> ch[i] >> d[i] >> a;
        min_a[ch[i] - 'a'] = min(min_a[ch[i] - 'a'], a);
    }

    vector<int> board(n);
    string str = "";

    for(int& b : board){
        cin >> b;
        str += ch[--b];
    }

    string target;
    cin >> target;

    int answer = 987654321;

    for(int i = 0; i <= n - k; i++){
        int result = 0;
        vector<priority_queue<int>> min_detach(26);
        for(int j = 0; j < k; j++){
            if(str[i + j] != target[j]){
                result += d[board[i + j]];
                min_detach[str[i + j] - 'a'].push(0);
            }
        }
        for(int j = 0; j < i; j++){
            min_detach[str[j] - 'a'].push(-d[board[j]]);
        }
        for(int j = i + k; j < n; j++){
            min_detach[str[j] - 'a'].push(-d[board[j]]);
        }
        for(int j = 0; j < k; j++){
            if(str[i + j] != target[j]){
                if(min_detach[target[j] - 'a'].empty()){
                    if(min_a[target[j] - 'a'] == 987654321){
                        cout << -1;
                        return 0;
                    }
                    result += min_a[target[j] - 'a'];
                }else{
                    if(-min_detach[target[j] - 'a'].top() < min_a[target[j] - 'a']){
                        result += -min_detach[target[j] - 'a'].top();
                        min_detach[target[j] - 'a'].pop();
                    }else{
                        result += min_a[target[j] - 'a'];
                    }
                }
            }
        }
        answer = min(answer, result);
    }

    cout << answer;

    return 0;
}