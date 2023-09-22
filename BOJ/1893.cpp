#include <iostream>
#include <vector>

using namespace std;

vector<int> get_pi(string& str){

    vector<int> pi(str.size());

    int l = 0;

    for(int i = 1; i < str.size(); i++){
        while(l > 0 and str[i] != str[l]){
            l = pi[l - 1];
        }
        if(str[i] == str[l]){
            pi[i] = ++l;
        }
    }

    return pi;

}

int kmp(string& str, string& p, vector<int>& pi){

    int idx = 0;

    int result = 0;

    for(int i = 0; i < str.size(); i++){
        while(idx > 0 and str[i] != p[idx]){
            idx = pi[idx - 1];
        }
        if(str[i] == p[idx]){
            if(idx == pi.size() - 1){
                result++;
                idx = pi[idx];
            }else{
                idx++;
            }
        }
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        string a, w, s;
        cin >> a >> w >> s;

        vector<int> answer;

        vector<char> next(128);
        for(int i = 0; i < a.size(); i++){
            next[a[i]] = a[(i + 1) % a.size()];
        }

        vector<int> pi = get_pi(w);

        for(int i = 0; i < a.size(); i++){
            if(kmp(s, w, pi) == 1){
                answer.push_back(i);
            }
            for(int j = 0; j < w.size(); j++){
                w[j] = next[w[j]];
            }
        }

        if(answer.size() == 0){
            cout << "no solution";
        }else if(answer.size() == 1){
            cout << "unique: ";
        }else{
            cout << "ambiguous: ";
        }
        for(int x : answer){
            cout << x << " ";
        }

        cout << "\n";
    }

    return 0;
}