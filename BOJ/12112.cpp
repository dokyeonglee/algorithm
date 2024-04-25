#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    vector<int> proper_divisior_sum(b + 1);

    for(int i = 1; i <= b; i++){
        for(int j = 2 * i; j <= b; j += i){
            proper_divisior_sum[j] += i;
        }
    }

    long long answer = 0;

    for(int i = a; i <= b; i++){
        answer += abs(i - proper_divisior_sum[i]);
    }

    cout << answer;

    return 0;
}