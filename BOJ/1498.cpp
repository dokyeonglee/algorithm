#include <iostream>
#include <vector>

using namespace std;

vector<int> get_pi(string& p){

    vector<int> pi(p.size());

    int l = 0;

    for(int i = 1; i < p.size(); i++){
        while(l > 0 and p[i] != p[l]){
            l = pi[l - 1];
        }
        if(p[i] == p[l]){
            pi[i] = ++l;
        }
    }

    return pi;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    auto pi = get_pi(str);

    for(int i = 1; i < str.size(); i++){
        if(pi[i] and (i + 1) % (i + 1 - pi[i]) == 0){
            cout << i + 1 << " " << (i + 1) / (i + 1 - pi[i]) << "\n";
        }
    }

    return 0;
}