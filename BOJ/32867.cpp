#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int answer = 0;

    int min_key = 2e5 + 1;
    int max_key = 0;

    while(n--){
        int x;
        cin >> x;
        min_key = min(min_key, x);
        max_key = max(max_key, x);
        if(max_key - min_key >= k){
            answer++;
            max_key = x;
            min_key = x;
        }
    }

    cout << answer;

    return 0;
}