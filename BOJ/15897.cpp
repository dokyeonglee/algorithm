#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    long long answer = 1;
    long long temp = 0;
    for(int i = 1; i < n; i = temp + 1){
        temp = (n - 1) / ((n - 1) / i);
        answer += (temp - i + 1) * ((n - 1) / i + 1);
    }

    cout << answer;

    return 0;
}