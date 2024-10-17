#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<pair<int, int>>>& tree, vector<int>& s, int now, vector<pair<int, long long>>& answer, long long sum){
    for(auto& e : tree[now]){
        int next = e.first;
        int x = e.second;
        if(x >= 0){//push x
            s.push_back(x);
            dfs(tree, s, next, answer, sum + x);
            s.pop_back();
        }else if(x == -1){//print
            answer.emplace_back(next, sum);
            dfs(tree, s, next, answer, sum);
        }else if(x == -2){//pop
            int temp = s.back();
            s.pop_back();
            dfs(tree, s, next, answer, sum - temp);
            s.push_back(temp);
        }else if(x == -3){//restore
            dfs(tree, s, next, answer, sum);
        }
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int idx = 0;

    int n;
    cin >> n;

    vector<vector<pair<int, int>>> tree(n + 1);

    for(int i = 1; i <= n; i++){
        string str;
        cin >> str;
        int x = -1;
        int p = i - 1;
        if(str == "print"){
        }else if(str == "pop"){
            x = -2;
        }else if(str == "push"){
            cin >> x;
        }else if(str == "restore"){
            x = -3;
            cin >> p;
        }
        tree[p].emplace_back(i, x);
    }

    vector<pair<int, long long>> answer;
    vector<int> s;

    dfs(tree, s, 0, answer, 0);

    sort(answer.begin(), answer.end());

    for(auto& a : answer){
        cout << a.second << "\n";
    }


    return 0;
}