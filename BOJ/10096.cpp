#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string str;
    cin >> str;

    if(n % 2 == 0){
        cout << "NOT POSSIBLE";
    }else{

        set<string> answer;

        string a = str.substr(0, n / 2);
        string b = str.substr(n / 2 + 1);

        if(a == b){
            cout << a;
        }else{
            int cnt = 0;
            int idx = n / 2;

            for(int i = 0; idx >= 0 and i < n / 2; i++){
                if(str[n - 1 - i] != str[idx]){
                    i--;
                    cnt++;
                }
                idx--;
            }

            if(cnt <= 1){
                answer.insert(b);
            }

            cnt = 0;
            idx = n / 2;

            for(int i = 0; idx < n and i < n / 2; i++){
                if(str[i] != str[idx]){
                    i--;
                    cnt++;
                }
                idx++;
            }

            if(cnt <= 1){
                answer.insert(a);
            }

            if(answer.size() > 1){
                cout << "NOT UNIQUE";
            }else if(answer.size() == 1){
                cout << *answer.begin();
            }else{
                cout << "NOT POSSIBLE";
            }
        }
    }

    return 0;
}