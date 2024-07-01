#include <iostream>
#include <vector>

using namespace std;

int T;
int k;

int dfs(vector<int>& fire, int pos, int t, int firewood){

    int n = fire.size() - 2;

    if(pos < 1 or pos > n){
        return 0;
    }

    vector<int> temp(n + 1);

    for(int i = 1; i <= n; i++){
        if(i == firewood){
            continue;
        }
        temp[i] = (fire[i - 1] <= 0) + (fire[i + 1] <= 0) + 1;
    }

    for(int i = 1; i <= n; i++){
        fire[i] -= temp[i];
    }

    int result = 0;

    if(t == T){
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            cnt += (fire[i] > 0);
        }
        if(cnt >= k){
            result = 1;
        }
    }else{
        for(int i = -1; i <= 1; i++){
            result += dfs(fire, pos + i, t + 1, pos + i);
        }
    }

    for(int i = 1; i <= n; i++){
        fire[i] += temp[i];
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, w;
    cin >> n >> w >> T >> k;

    vector<int> fire(n + 2);

    for(int i = 1; i <= n; i++){
        cin >> fire[i];
    }

    cout << dfs(fire, w + 1, 1, -1);

    return 0;
}