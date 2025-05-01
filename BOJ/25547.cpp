#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    if(b % a){
        cout << 0;
        return 0;
    }

    int answer = 1;

    int x = b / a;

    for(int i = 2; i * i <= x; i++){
        int y = 1;
        while(x % i == 0){
            y++;
            x /= i;
        }
        answer *= y;
    }

    if(x > 1){
        answer *= 2;
    }

    cout << answer;

    return 0;

}