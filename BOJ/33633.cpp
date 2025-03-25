#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> answer;

void dfs(long long now, int n){
    if(n == 1){
        answer.push_back(now);
        return;
    }
    dfs(now * 2, n - 1);
    if(now != 4 and now % 3 == 1 and (now - 1) / 3 % 2 == 1){
        dfs((now - 1) / 3, n - 1);
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    dfs(1, n);

    sort(answer.begin(), answer.end());

    cout << answer.size() << "\n";
    for(auto& a : answer){
        cout << a << "\n";
    }

    return 0;

}