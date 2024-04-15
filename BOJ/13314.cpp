#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> arr(100, vector<int>(100, 100));

    for(int i = 0; i < 100; i++){
        arr[i][i] = 0;
    }

    for(int i = 0; i < 99; i++){
        arr[i][99] = 1;
        arr[99][i] = 1;
    }

    cout << "100\n";

    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}