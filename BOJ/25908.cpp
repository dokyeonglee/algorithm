#include <iostream>
#include <vector>

using namespace std;

long long solve(long long n){
    long long result = 0;
    int s = -1;
    for(int i = 1; i <= n; i++){
        result += s * (n / i);
        s = -s;
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long s, t;
    cin >> s >> t;

    cout << solve(t) - solve(s - 1);

    return 0;
}