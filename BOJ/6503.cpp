#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(1){

        int m;
        cin >> m;

        cin.ignore();

        if(m == 0){
            break;
        }

        string str;

        getline(cin, str);

        vector<int> cnt(128);

        int left = -1;
        int right = -1;

        int number_of_key = 0;

        int answer = 0;

        while(right + 1 < str.size()){
            if(number_of_key < m or cnt[str[right + 1]]){
                if(++cnt[str[++right]] == 1){
                    number_of_key++;
                }
            }else{
                if(--cnt[str[++left]] == 0){
                    number_of_key--;
                }
            }
            answer = max(answer, right - left);
        }

        cout << answer << "\n";

    }

    return 0;
}