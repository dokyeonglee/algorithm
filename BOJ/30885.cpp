#include <iostream>
#include <list>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    list<pair<long long, int>> l;
    
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        l.emplace_back(x, i);
    }

    while(l.size() > 1){
        auto it = l.begin();
        while(it != l.end()){
            long long temp = it->first;
            if(it != l.begin()){
                auto prev_it = prev(it);
                if(prev_it->first <= temp){
                    it->first += prev_it->first;
                    l.erase(prev_it);
                }
            }
            auto next_it = next(it);
            if(next_it != l.end()){
                if(next_it->first <= temp){
                    it->first += next_it->first;
                    l.erase(next_it);
                }
            }
            it = next(it);
        }
    }

    cout << l.front().first << "\n";
    cout << l.front().second;

    return 0;
}