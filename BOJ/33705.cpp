#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n + 1);

    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        arr[i] = arr[i - 1] + (x == 1);
    }

    if(arr[n] >= (n + 1)/ 2){
        cout << 0;
    }else{

        bool check = false;

        for(int i = 1; i < n; i++){
            if(arr[n] - arr[i] >= (n - i + 1) / 2){
                check = true;
                break;
            }
        }

        if(!check){
            for(int i = n; i > 1; i--){
                if(arr[i - 1] >= i / 2){
                    check = true;
                    break;
                }
            }
        }

        if(check){
            cout << 1;
        }else{
            cout << 2;
        }

    }

    return 0;

}