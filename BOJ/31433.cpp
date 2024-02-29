#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    int n = str.size();

    string ksa_str = "KSA";

    int answer = 1e9;

    for(int j = 0; j < 3; j++){
        int idx = j;
        int length = 0;
        for(int i = 0; i < n; i++){
            if(str[i] == ksa_str[idx]){
                length++;
                idx = (idx + 1) % 3;
            }
        }
        if(length + j > n){
            answer = min(answer, 2 * j);
        }else{
            answer = min(answer, 2 * (n - length));
        }
    }

    cout << answer;

    return 0;
}