#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long left = 1e9 + 1;
    long long right = -left;

    int n, d;
    cin >> n >> d;

    while(n--){
        long long x;
        cin >> x;
        left = min(left, x);
        right = max(right, x);
    }

    long long answer = 0;

    if(left >= 0){
        answer = 2 * right + d;
    }else if(right <= 0){
        answer = 2 * -left + d;
    }else{
        answer = 2 * (-left + right + d);
        answer = min(answer, 2 * (-left + -left + right) + d);
        answer = min(answer, 2 * (-left + right + right) + d);
        if(2 * (-left + right) >= d){
            answer = min(answer, 4 * (-left + right));
        }else{
            answer = min(answer, 2 * (-left + right) + d);
        }
    }

    cout << answer;

    return 0;
}