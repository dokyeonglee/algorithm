#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

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

int kmp(string& s, string& p){

    vector<int> pi = get_pi(p);

    int result = 0;
    int idx = 0;

    for(int i = 0; i < s.size(); i++){
        while(idx > 0 and s[i] != p[idx]){
            idx = pi[idx - 1];
        }
        if(s[i] == p[idx]){
            if(idx == p.size() - 1){
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

    int n;
    cin >> n;

    vector<string> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int k;
    cin >> k;

    vector<int> temp(n);
    for(int i = 0; i < n; i++){
        temp[i] = i;
    }

    int answer = 0;

    map<string, int> mp;
    
    do{
        string s = "";
        for(int i = 0; i < n; i++){
            s += arr[temp[i]];
        }
        mp[s]++;
    }while(next_permutation(temp.begin(), temp.end()));

    for(auto& it : mp){
        string s = it.first;
        string p = s;
        s += s;
        s.pop_back();
        if(kmp(s, p) == k){
            answer += it.second;
        }
    }

    cout << answer;

    return 0;
}