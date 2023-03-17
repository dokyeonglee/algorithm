#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    int n = str.size() + 3;

    vector<char> s = vector<char>(3, ' ');
    for(int i = 3; i < n; i++){
        if(str[i - 3] == 'P'){
            int t = s.size();
            if(s[t - 3] == 'P' and s[t - 2] == 'P' and s[t - 1] == 'A'){
                for(int j = 0; j < 3; j++){
                    s.pop_back();
                }
            }
        }
        s.push_back(str[i - 3]);
    }

    if(s.size() == 4 and s.back() == 'P'){
        cout << "PPAP";
    }else{
        cout << "NP";
    }

    return 0;
}