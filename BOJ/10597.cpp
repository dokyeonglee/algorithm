#include <iostream>
#include <vector>

using namespace std;

void solve(string& str, vector<bool>& visited, vector<int>& answer, int idx){

    int n = visited.size() - 1;

    if(idx == str.size()){
        for(auto& a : answer){
            cout << a << " ";
        }
        exit(0);
    }

    int x = 0;

    for(int i = 0; i < 2; i++){
        x = 10 * x + (str[idx + i] - '0');
        if(x > n){
            continue;
        }
        if(visited[x]){
            continue;
        }
        visited[x] = true;
        answer.push_back(x);
        solve(str, visited, answer, idx + i + 1);
        visited[x] = false;
        answer.pop_back();
    }


}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    if(str.size() < 10){
        for(auto& c : str){
            cout << c << " ";
        }
    }else{
        int n = (str.size() - 9) / 2 + 9;
        vector<bool> visited(n + 1);
        vector<int> answer;
        solve(str, visited, answer, 0);
    } 

    return 0;
}