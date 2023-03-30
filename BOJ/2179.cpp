#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    unordered_map<string, vector<int>> mp;
    vector<string> arr(n);
    for(int i = 0; i < n; i++){ 
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        string s = arr[i];
        int sz = s.size();
        for(int j = 0; j < sz; j++){
            if(mp[s].size() < 2){
                mp[s].push_back(i);
            }
            s.pop_back();
        }
    }

    vector<int> idx = {987654321, 987654321};
    int sz = 0;

    for(auto it : mp){
        if(it.second.size() == 2){
            if(sz < it.first.size()){
                sz = it.first.size();
                idx = it.second;
            }else if(sz == it.first.size()){
                if(idx > it.second){
                    idx = it.second;
                }
            }
        }
    }

    if(idx[0] == 987654321){
        idx[0] = 0;
        idx[1] = 1;
    }

    cout << arr[idx[0]] << "\n";
    cout << arr[idx[1]];

    return 0;
}