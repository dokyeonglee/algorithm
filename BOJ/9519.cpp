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

    string temp = str;

    vector<string> answer;
    answer.push_back(str);

    while(1){
        for(int i = 0; i < (str.size() - 1) / 2; i++){
            temp.insert(temp.begin() + 2 * i + 1, temp.back());
            temp.pop_back();
        }
        if(temp == str){
            break;
        }
        answer.push_back(temp);
    }

    n %= answer.size();

    cout << answer[(answer.size() - n) % answer.size()];

    return 0;
}