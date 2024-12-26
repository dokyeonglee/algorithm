#include <iostream>
#include <vector>

using namespace std;

int solve(int p1, int p2, int m, int s, int n){
    int result = 1e9;
    if((m - p1) % 2 != 0 and m != n and s != n){
        result = 0;
        if(m > p2){
            if((m - p2) % 2 == 0){
                result += m - p2 + 1;
                p2 = m + 1;
            }else{
                return 1e9;
            }
        }
        result += abs(m - p1);
        if(p2 <= s){
            result += s - p2 + 1;
        }
        result += abs(m - s);
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int p1, p2;
    cin >> p1 >> p2;

    int m;
    cin >> m;

    int s;
    cin >> s;

    int answer = min(solve(p1, p2, m, s, n), solve(n + 1 - p2, n + 1 - p1, n + 1 - m, n + 1 - s, n));
    if(answer == 1e9){
        answer = -1;
    }

    cout << answer;

    return 0;
}