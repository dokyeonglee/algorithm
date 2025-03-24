#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a;
    long long sum = 0;
    long long gain = 0;
    long long answer = 0;
    long long immunity = 0;

    
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a;
        gain = max(gain, a - sum);
        sum += a;
        if(immunity < sum){
            int x = sum - immunity;
            int y = (x + gain - 1) / gain;
            answer += y;
            immunity += y * gain;
        }
    }

    cout << answer;

    return 0;

}