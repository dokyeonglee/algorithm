#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    long long largest_mana = -1e9;
    long long second_largest_mana = -1e9;

    while(m--){
        int x;
        cin >> x;
        if(largest_mana <= x){
            second_largest_mana = largest_mana;
            largest_mana = x;
        }else if(second_largest_mana < x){
            second_largest_mana = x;
        }
    }

    const int mod = 1e9 + 7;

    if(largest_mana < 0){
        cout << (largest_mana + second_largest_mana + mod) % mod;
    }else{
        while(second_largest_mana < 0 and n--){
            second_largest_mana += largest_mana;
        }
        if(n <= 0){
            cout << (second_largest_mana + mod) % mod;
        }else{
            while(n--){
                long long temp = largest_mana;
                largest_mana += second_largest_mana;
                second_largest_mana = temp;
                largest_mana %= mod;
            }
            cout << largest_mana % mod;
        }
    }
    return 0;
}