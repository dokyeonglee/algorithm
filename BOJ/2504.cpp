#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    int answer = 0;

    stack<char> s;

    int temp = 1;

    for(int i = 0; i < str.size(); i++){

        if(str[i] == '('){
            temp *= 2;
            s.push('(');
        }else if(str[i] == '['){
            temp *= 3;
            s.push('[');
        }else{

            if(s.empty() or (str[i] == ')' and s.top() == '[') or (str[i] == ']' and s.top() == '(')){
                cout << 0;
                return 0;
            }

            if(str[i] == ')'){
                if(str[i - 1] == '('){
                    answer += temp;
                }
                temp /= 2;
            }else if(str[i] == ']'){
                if(str[i - 1] == '['){
                    answer += temp;
                }
                temp /= 3;
            }

            s.pop();

        }

    }

    if(!s.empty()){
        answer = 0;
    }

    cout << answer;

    return 0;
}