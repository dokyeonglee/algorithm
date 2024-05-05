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
        int x, y;
        cin >> x >> y;
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto& a : arr){
            cin >> a;
        }
        int g = arr[0];
        for(int i = 1; i < n; i++){
            g = gcd(g, arr[i]);
        }
        if(x % g == 0 and y % g == 0){
            cout << "Ta-da\n";
        }else{
            cout << "Gave up\n";    
        }
    }

    return 0;
}