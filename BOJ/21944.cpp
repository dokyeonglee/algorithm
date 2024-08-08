#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    map<int, pair<int, int>> problems;
    map<int, set<int>> difficulty;
    map<int, set<pair<int, int>>> algorithm;

    int p, l, g;

    for(int i = 0; i < n; i++){
        cin >> p >> l >> g;
        problems[p] = make_pair(l, g);
        difficulty[l].emplace(p);
        algorithm[g].emplace(l, p);
    }

    int q;
    cin >> q;

    int x;

    while(q--){
        string command;
        cin >> command;
        if(command[0] == 'r'){
            if(command.back() == 'd'){
                cin >> g >> x;
                if(x == 1){
                    cout << algorithm[g].rbegin()->second << "\n";
                }else{
                    cout << algorithm[g].begin()->second << "\n";
                }
            }else if(command.back() == '2'){
                cin >> x;
                if(x == 1){
                    cout << *difficulty.rbegin()->second.rbegin() << "\n";
                }else{
                    cout << *difficulty.begin()->second.begin() << "\n";
                }
            }else if(command.back() == '3'){
                cin >> x >> l;
                auto it = difficulty.lower_bound(l);
                if(x == 1){
                    if(it == difficulty.end()){
                        cout << "-1\n";
                    }else{
                        cout << *it->second.begin() << "\n";
                    }
                }else{
                    if(it == difficulty.begin()){   
                        cout << "-1\n";
                    }else{
                        it--;
                        cout << *it->second.rbegin() << "\n";
                    }
                }
            }
        }else if(command[0] == 'a'){
            cin >> p >> l >> g;
            problems[p] = make_pair(l, g);
            difficulty[l].emplace(p);
            algorithm[g].emplace(l, p);
        }else if(command[0] == 's'){
            cin >> p;
            l = problems[p].first;
            g = problems[p].second;
            problems.erase(p);
            difficulty[l].erase(p);
            if(difficulty[l].size() == 0){
                difficulty.erase(l);
            }
            algorithm[g].erase(make_pair(l, p));
            if(algorithm[g].size() == 0){
                algorithm.erase(g);
            }
        }
    }

    return 0;
}