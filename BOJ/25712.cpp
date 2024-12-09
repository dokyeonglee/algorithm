#include <iostream>
#include <vector>

using namespace std;

bool is_overlapped(pair<int, int>& a, pair<int, int>& b){
    return max(a.first, b.first) <= min(a.second, b.second);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> length(m);
    for(int& l : length){
        cin >> l;
    }

    vector<pair<int, int>> now{make_pair(0, n)};

    for(int i = 0; i < m; i++){
        vector<pair<int, int>> next;
        vector<pair<int, int>> temp;
        while(length[i] > 0){
            int s, e;
            cin >> s >> e;
            temp.emplace_back(s, e);
            length[i] -= 2;    
        }
        int idx = 0;
        for(int k = 0; k < temp.size(); k++){
            for(int j = idx; j < now.size(); j++){
                if(is_overlapped(now[j], temp[k])){
                    next.push_back(temp[k]);
                    idx = j;
                    break;
                }
            }
        }
        now = next;
        if(next.size() == 0){
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}