#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    if(k == 1){
        cout << "NO";
    }else{

        vector<int> arr(n + 1);
        for(int i = 1; i <= n; i++){
            arr[i] = i;
        }

        if(k % 2 == 1){
            if(n == k){
                cout << "NO";
                return 0;
            }
            for(int i = k + 1; i <= n; i += 2 * k){
                swap(arr[i - 1], arr[i]);
            }
            if(n / k % 2 == 1){
                swap(arr[n - (k - 1)], arr[n - (k - 1) - k + 1]);
            }
        }

        cout << "YES\n";
        for(int i = 1; i <= n; i++){
            cout << arr[i] << " ";
            if(i % k == 0){
                cout << '\n';
            }
        }

    }

    return 0;
}