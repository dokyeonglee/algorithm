#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> arr(n + 1);
    vector<long long> f(n + 1);

    for(int i = 0; i <= n; i++){
        cin >> arr[i] >> f[i];
    }

    for(int i = 1; i <= n; i++){
        f[i] += f[i - 1];
    }

    long long temp = 0;
    int idx = 0;

    for(int i = 1; i <= n; i++){
        if(f[i - 1] < arr[i]){
            for(int j = i; j <= n; j++){
                cout << "-1 -1\n";
            }
            return 0;
        }
        cout << idx << " " << f[i - 1] - arr[i] - temp << "\n";
        if(f[i - 1] - arr[i] <= temp){
            temp = f[i - 1] - arr[i];
            idx = i;
        }
        
    }


    return 0;
}