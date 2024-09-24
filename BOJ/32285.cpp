#include <iostream>
#include <vector>

using namespace std;

int solve(long long g){
    return __builtin_popcountll(g) + 64 - __builtin_clzll(g) - 1;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long g, f;
    cin >> g >> f;

    long long cnt = (1ll << solve(g));

    int answer = g;

    for(; g <= cnt; g += f){
        answer = min(answer, solve(g));
    }

    cout << answer;

    return 0;
}