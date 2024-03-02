#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int r = n % 2;

    cout << "YES\n";

    if(r){
        cout << "1 ";
    }

    int d[] = {1, 0, 2, 3};

    for(int i = 1 + r; i < n; i += 4){
        for(int j = 0; j < 4 and j + i <= n; j++){
            cout << i + d[j] << " ";
        }
    }

    return 0;
}