#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    string str;
    cin >> str;

    vector<int> r_idx(str.size() + 5, str.size());
    vector<int> b_idx(str.size() + 5, str.size());

    for(int i = 0; i < str.size(); i++){
        if(str[i] == 'R'){
            r_idx[i] = i;
        }else if(str[i] == 'B'){
            b_idx[i] = i;
        }
    }

    for(int i = str.size() - 1; i >= 0; i--){
        r_idx[i] = min(r_idx[i], r_idx[i + 1]);
        b_idx[i] = min(b_idx[i], b_idx[i + 1]);
    }


    while(q--){
        int l, r;
        cin >> l >> r;
        int a = r_idx[l];
        int b = r_idx[r_idx[a] + 1];
        int c = b_idx[r_idx[b] + 1];
        int d = b_idx[b_idx[c] + 1];
        if(d > r){
            cout << "-1\n";
        }else{
            cout << a << " " << b << " " << c << " " << d << "\n";
        }
    }

    return 0;
}