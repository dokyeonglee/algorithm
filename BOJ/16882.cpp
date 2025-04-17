#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> cnt(1e5 + 1);
    
    int cnt_odd = 0;

    while(n--){
        int a;
        cin >> a;
        if(cnt[a]++ & 1){
            cnt_odd--;
        }else{
            cnt_odd++;
        }
    }

    if(cnt_odd){
        cout << "koosaga";
    }else{
        cout << "cubelover";
    }

    return 0;

}