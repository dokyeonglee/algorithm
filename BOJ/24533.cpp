#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    long long answer = 0;

    long long sum_of_x = 0;
    long long sum_of_y = 0;

    while(n--){
        int x, y;
        cin >> x >> y;
        sum_of_x += x;
        sum_of_y += y;
        answer -= 1ll * x * y;
    }

    answer += sum_of_x * sum_of_y;

    cout << answer;

    return 0;

}