#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    cout << "YES\n";
    
    string str(m, '0');
    for(int i = 1; i < m; i += 2){
        str[i] = '1';
    }

    for(int i = 0; i < n - 2; i++){
        cout << str << "\n";
    }

    for(int i = 0; i < m; i++){
        cout << 1;
    }

    cout << "\n";

    for(int i = 0; i < m; i++){
        cout << 0;
    }

    return 0;
}