#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<string> arr(n);
    for(auto& a : arr){
        cin >> a;
    }

    vector<string> sub(n);

    string str;

    for(int i = 0; i < m; i++){
        map<string, int> cnt;
        for(int j = 0; j < n; j++){
            sub[j] += arr[j][i];
            cnt[sub[j]]++;
        }
        for(auto& it : cnt){
            if(it.second <= k){
                str = it.first;
                break;
            }
        }
        if(str.size()){
            break;
        }
    }

    if(str.size() == 0){
        cout << -1;
    }else{
        cout << str.size() << "\n";
        for(auto& c : str){
            if(c == 'R'){
                cout << 'S';
            }else if(c == 'S'){
                cout << 'P';
            }else{
                cout << 'R';
            }
        }
    }

    return 0;
}