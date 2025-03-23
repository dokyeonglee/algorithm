#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<long long> arr(n + 1);

    while(m--){
        int w, d;
        cin >> w >> d;
        arr[w] = d;
    }

    for(int i = 1; i <= n; i++){
        arr[i] += arr[i - 1];
    }

    int left = 1;
    int right = n;

    while(q--){
        int p;
        cin >> p;
        long long hammer = 0;
        if(p >= left and p <= right){
            long long escape_left = arr[p] - arr[left - 1];
            long long escape_right = arr[right] - arr[p - 1];
            if(escape_left < escape_right){
                left = p;
                hammer = escape_left;
            }else if(escape_left == escape_right){
                if(p - 1 <= n - p){
                    left = p;
                }else{
                    right = p;
                }
                hammer = escape_left;
            }else{
                right = p;
                hammer = escape_right;
            }
        }
        cout << hammer << "\n";
    }

    return 0;

}