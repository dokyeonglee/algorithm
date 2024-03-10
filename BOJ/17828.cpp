#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    if(26 * n < x or n > x){
        cout << '!';
    }else{
        string answer(n, 'Z');
        int y = 26 * n - (26 * n - x) / 25 * 25;
        for(int i = 0; i < (26 * n - x) / 25; i++){
            answer[i] = 'A';
        }
        answer[(26 * n - x) / 25] -= y - x;
        cout << answer;
    }

    return 0;
}