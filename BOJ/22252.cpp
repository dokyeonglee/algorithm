#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<string, priority_queue<int>> gorilla;

    int q;
    cin >> q;

    long long answer = 0;

    while(q--){

        int c;
        string name;

        cin >> c >> name;

        auto& g = gorilla[name];

        if(c == 1){
            int k, x;
            cin >> k;
            while(k--){
                cin >> x;
                g.emplace(x);
            }    
        }else{
            int x;
            cin >> x;
            int sz = min(x, (int)g.size());
            while(sz--){
                answer += g.top();
                g.pop();
            }
        }

    }

    cout << answer;

    return 0;

}