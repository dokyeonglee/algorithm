#include <iostream>
#include <vector>
#include <stack>

using namespace std;

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

        string answer;

        for(int i = 0; i < n; i++){
            int cnt = 1;
            if(str[i] == 'B'){
                cnt = 0;
                while(answer.size() > 1 and answer[answer.size() - 2] == 'A' and answer[answer.size() - 1] == 'B'){
                    answer.pop_back();
                    answer.pop_back();
                    cnt++;
                }
                answer.push_back('B');
                
            }
            while(cnt--){
                answer.push_back('A');
            }
        }

        cout << answer << "\n";
        
    }

    return 0;

}