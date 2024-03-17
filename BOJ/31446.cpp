#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, two_s;
    cin >> n >> two_s;

    if(n - 2 > two_s){
        cout << "NO";
    }else{
        vector<pair<int, int>> answer;

        for(int i = 1; i <= n / 2; i++){
            answer.emplace_back(1 + i % 2, i);
        }

        for(int i = (n + 1) / 2; i >= 1; i--){
            answer.emplace_back(i % 2, i);
        }
        
        answer[0].first += two_s - (n - 2);

        cout << "YES\n";
        for(auto& p : answer){
            cout << p.first << " " << p.second << "\n";
        }
    }

    return 0;
}