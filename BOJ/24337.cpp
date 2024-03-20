#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cout.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    if(a + b > n + 1){
        cout << -1;
    }else{

        if(a == 1){
            cout << b << " ";
        }

        for(int i = 0; i < n - (a + b - 1); i++){
            cout << "1 ";
        }

        for(int i = 1; i <= a - 1; i++){
            cout << i << " ";
        }

        if(a > b){
            cout << a << " ";
        }else if(a != 1){
            cout << b << " ";
        }

        for(int i = b - 1; i >= 1; i--){
            cout << i << " ";
        }

    }

    return 0;
}