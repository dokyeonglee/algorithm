#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> arr(2 * n);
 
    for(int i = 0; i < m; i++){

        int x, y, z;
        cin >> x >> y >> z;

        arr[x]++;
        arr[x + y]++;
        arr[x + y + z] -= 2;

    }

    arr[0]++;
    
    for(int i = 1; i < arr.size(); i++){
        arr[i] += arr[i - 1];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j == 0){
                cout << arr[n - 1 - i] << " ";
            }else{
                cout << arr[n + j - 1] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}