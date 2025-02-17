#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    vector<long long> fib(51);

    fib[1] = 1;

    for(int i = 2; i <= 50; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    while(t--){
        int x, y;
        cin >> x >> y;
        int idx = 1;
        for(int i = 50; i >= 1; i--){
            if(fib[i] <= x and fib[i - 1] <= y){
                idx = i;
                break;
            }
        }
        cout << fib[idx] << " " << fib[idx - 1] << "\n";
    }

    return 0;

}