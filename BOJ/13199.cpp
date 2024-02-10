#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        int p, m, f, c;
        cin >> p >> m >> f >> c;
        
        int cnt = m / p * c / f * c + m / p * c % f;

        int answer = 0;

        if(cnt >= f){
            answer += (cnt - f) / (f - c) + 1;
        }

        cout << answer << "\n";

    }

    return 0;
}