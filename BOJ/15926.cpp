#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string str;
    cin >> str;

    vector<int> v{-1};

    int answer = 0;

    for(int i = 0; i < n; i++){
        if(str[i] == '('){
            v.push_back(i);
        }else{
            v.pop_back();
            if(v.size()){
                answer = max(answer, i - v.back());
            }else{
                v.push_back(i);
            }
        }
    }

    cout << answer;

    return 0;

}