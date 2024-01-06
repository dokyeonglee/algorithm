#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    string str;
    cin >> str;

    vector<pair<int, int>> arr;
    int cnt = 1;

    for(int i = 1; i < n; i++){
        if(str[i] == str[i - 1]){
            cnt++;
        }else{
            if(cnt >= k){
                arr.emplace_back(i - cnt, i - 1);
            }
            cnt = 1;
        }
    }

    if(cnt >= k){
        arr.emplace_back(n - cnt, n - 1);
    }

    int answer = k - 1;

    for(int l = n; l >= k; l--){
        bool check = true;
        for(auto& a : arr){
            if(a.first / l == a.second / l){
                check = false;
                break;
            }
            if(a.second - a.first + 1 >= 2 * l){
                check = false;
                break;
            }
            if(a.second / l * l - a.first >= k or a.second - a.second / l * l + 1 >= k){
                check = false;
                break;
            }
        }
        if(check){
            answer = l;
            break;
        }
    }

    cout << answer;

    return 0;
}