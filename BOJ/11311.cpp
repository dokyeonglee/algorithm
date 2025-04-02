#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int a, b, d;
        cin >> a >> b >> d;
        if(d % gcd(a, b) == 0){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }

    return 0;

}