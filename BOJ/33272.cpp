#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    if(n > m){
        cout << -1;
        return 0;
    }

    vector<int> answer;

    for(int i = 1; i <= m; i++){
        if(i == k or (i ^ k) > i){
            answer.push_back(i);
            if(answer.size() == n){
                break;
            }
        }
    }

    if(answer.size() != n){
        cout << -1;
    }else{
        for(auto& a : answer){
            cout << a << " ";
        }
    }

    return 0;

}