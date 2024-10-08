#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> is_prime(1e7, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i * i < 1e7; i++){
        if(is_prime[i]){
            for(int j = i * i; j < 1e7; j += i){
                is_prime[j] = false;
            }
        }
    }

    int t;
    cin >> t;

    while(t--){
        string str;
        cin >> str;
        sort(str.begin(), str.end());
        set<int> s;
        do{
            for(int i = 0; i < str.size(); i++){
                int num = 0;
                for(int j = 0; j <= i; j++){
                    num = num * 10 + (str[j] - '0');
                    if(is_prime[num]){
                        s.insert(num);
                    }
                }
            }
        }while(next_permutation(str.begin(), str.end()));

        int answer = s.size();

        cout << answer << "\n";
    }

    return 0;
}