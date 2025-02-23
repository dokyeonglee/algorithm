#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    vector<int> cnt(26);

    for(char& c : s){
        cnt[c - 'a']++;
    }

    int n;
    cin >> n;

    while(n--){

        string t;
        cin >> t;

        bool possible = false;

        if(s.size() <= t.size()){

            vector<int> cnt2(26);
            for(int i = 0; i < s.size(); i++){
                cnt2[t[i] - 'a']++;
            }

            int one = 0;
            int minus_one = 0;
            int diff_cnt = 0;

            for(int i = 0; i < 26; i++){
                if(cnt[i] != cnt2[i]){
                    diff_cnt++;
                }
                if(cnt[i] - cnt2[i] == 1){
                    one++;
                }
                if(cnt[i] - cnt2[i] == -1){
                    minus_one++;
                }
            }

            if((s.size() < t.size() and diff_cnt == 0) or diff_cnt == 2 and one == 1 and minus_one == 1){
                possible = true;
            }else{
                int idx = s.size();
                while(idx < t.size()){
                    if(t[idx] != t[idx - s.size()]){
                        cnt2[t[idx - s.size()] - 'a']--;
                        cnt2[t[idx] - 'a']++;
                        int temp = cnt[t[idx - s.size()] - 'a'] - cnt2[t[idx - s.size()] - 'a'];
                        if(temp == -1){
                            minus_one++;
                        }else if(temp == 0){
                            diff_cnt--;
                            minus_one--;
                        }else if(temp == 1){
                            diff_cnt++;
                            one++;
                        }else if(temp == 2){
                            one--;
                        }
                        temp = cnt[t[idx] - 'a'] - cnt2[t[idx] - 'a'];
                        if(temp == -2){
                            minus_one--;
                        }else if(temp == -1){
                            diff_cnt++;
                            minus_one++;
                        }else if(temp == 0){
                            diff_cnt--;
                            one--;
                        }else if(temp == 1){
                            one++;
                        }
                        if(diff_cnt == 0 or (diff_cnt == 2 and one == 1 and minus_one == 1)){
                            possible = true;
                            break;
                        }
                    }
                    idx++;
                }
            }
        }

        if(possible){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }

    }

    return 0;

}