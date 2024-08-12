#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    string answer = "";

    while(n > 0){
        if(n & 1){
            answer.push_back('/');
            n *= 2;
        }else if(n & 2){
            answer.push_back('+');
            n -= 2;
        }else{
            answer.push_back('*');
            n /= 2;
        }
    }

    if(answer.size() > 99){
        cout << -1;
    }else{
        cout << answer.size() << "\n";
        for(int i = answer.size() - 1; i >= 0; i--){
            cout << "[" << answer[i] << "] ";
        }
    }

    return 0;
}