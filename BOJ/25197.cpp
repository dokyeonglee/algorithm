#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    cout << fixed;
    cout.precision(10);
    
    cout << n * (n - 1) / 2 / (double)k;    

    return 0;
}