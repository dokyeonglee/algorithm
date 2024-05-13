#include <iostream>
#include <vector>

using namespace std;

char solve(vector<char>& operands, vector<char>& operators){

    char result = operands[0];

    for(int i = 0; i < operators.size(); i++){
        if(operators[i] == '&'){
            if(operands[i + 1] == 'F'){
                result = 'F';
            }
        }else{
            if(operands[i + 1] == 'T'){
                result = 'T';
            }
        }
    }

    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<char> operands;
    vector<char> operators;

    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        if(i % 2 == 0){
            operands.push_back(c);
        }else{
            operators.push_back(c);
        }
    }

    char target;
    cin >> target;

    if(solve(operands, operators) == target){
        cout << 0;
        return 0;
    }

    for(int i = 0; i < operands.size(); i++){
        if(operands[i] == 'T'){
            operands[i] = 'F';
            if(solve(operands, operators) == target){
                cout << 1;
                return 0;
            }
            operands[i] = 'T';
        }else{
            operands[i] = 'T';
            if(solve(operands, operators) == target){
                cout << 1;
                return 0;
            }
            operands[i] = 'F';
        }
    }

    for(int i = 0; i < operators.size(); i++){
        if(operators[i] == '|'){
            operators[i] = '&';
            if(solve(operands, operators) == target){
                cout << 1;
                return 0;
            }
            operators[i] = '|';
        }else{
            operators[i] = '|';
            if(solve(operands, operators) == target){
                cout << 1;
                return 0;
            }
            operators[i] = '&';
        }
    }

    cout << 2;
    return 0;
}