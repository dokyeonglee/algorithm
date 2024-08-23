#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);

    arr[0] = 1;
    arr[1] = 3;
    arr[2] = 5;
    arr[(n - 1) / 2] = 7;
    arr[(n - 1) / 2 + 1] = 2;
    arr[(n - 1) / 2 + 2] = 4;
    arr[(n - 1) / 2 + 3] = 6;
    arr[n - 1] = 8;

    for(int i = 3; i < (n - 1) / 2; i++){
        arr[i] = 2 * i + 3;
    }

    for(int i = (n - 1) / 2 + 4; i < n - 1; i++){
        arr[i] = 2 * ((i - (n - 1) / 2) + 1);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[(i + j) % n] << " ";
        }
        cout << "\n";
    }

    return 0;
}