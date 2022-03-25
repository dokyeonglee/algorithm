#include <iostream>

using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while(T--){
        int a, b, c;
        cin >> a >> b >> c;
        if(c > a and c > b){
            cout << "NO\n";
        }else if(c % gcd(a, b) == 0){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}