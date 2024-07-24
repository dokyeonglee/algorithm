#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        vector<pair<int, pair<int, int>>> arr;

        int a, b;
        cin >> a >> b;

        int base_a = 10;
        int base_b = 10;

        while(1){
            int x = a / 100 * base_a * base_a + a / 10 % 10 * base_a + a % 10;
            int y = b / 100 * base_b * base_b + b / 10 % 10 * base_b + b % 10;
            if(x == y){
                break;
            }
            if(x < y){
                base_a++;
            }else{
                base_b++;
            }
        }

        cout << base_a << " " << base_b << "\n";

    }

    return 0;
}