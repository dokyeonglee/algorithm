#include <iostream>
#include <vector>

using namespace std;


int solve(string& str){

    int n = str.size();

    if(str[0] != str[n - 1]){

        int idx = 0;
        int cnt = 0;
        int cnt2 = 0;

        while(idx < n and str[idx] == str[0]){
            idx++;
            cnt++;
        }

        idx = n - 1;

        while(idx >= 0 and str[idx] == str[n - 1]){
            idx--;
            cnt2++;
        }

        if(cnt == cnt2){
            return 0;
        }

        if(abs(cnt - cnt2) > 1 or cnt + cnt2 < n){
            return 1;
        }

    }

    int x = (str[0] == '1') + (str[1] == '0') + (str[n - 2] == '1') + (str[n - 1] == '0');

    return min(x, 4 - x);

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        string str; 
        cin >> str;

        if(n == 1 or n == 3){
            cout << "-1\n";
        }else if(n == 2){
            cout << (str[0] == str[1]) << "\n";
        }else{
            cout << solve(str) << "\n";
        }

    }

    return 0;
}