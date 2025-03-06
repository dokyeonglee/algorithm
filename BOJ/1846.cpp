#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if(n == 3){
        cout << -1;
        return 0;
    }

    cout << (n + 1) / 2 << "\n";

    for(int i = 1; i < (n + 1) / 2; i++){
        cout << i << "\n";
    }

    if(n % 2 == 1){
        cout << n << "\n";
    }

    for(int i = n / 2 + 2; i < n; i++){
        cout << i << "\n";
    }

    if(n % 2 == 0){
        cout << n << "\n";
        cout << n / 2 + 1;
    }

    return 0;

}