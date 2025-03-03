#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long p[11] = {1};

    for(int i = 1; i <= 10; i++){
        p[i] = 26 * p[i - 1] + 1;
    }

    int n;
    cin >> n;

    string str;
    cin >> str;

    long long answer = 0;

    for(int i = 0; i < str.size(); i++){
        answer += (str[i] - 'a') * p[n - 1 - i] + 1;
    }

    cout << answer;

    return 0;

}