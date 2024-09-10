#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int phi = m;

    for(int i = 2; i * i <= m; i++){
        if(m % i == 0){
            phi = phi - phi / i;
            while(m % i == 0){
                m /= i;
            }
        }
    }

    if(m > 1){
        phi = phi - phi / m;
    }

    cout << phi;

    return 0;
}