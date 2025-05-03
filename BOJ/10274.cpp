#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    int global_max;
    int global_min;
    int current_max;
    int current_min;
    int sum;
    int n;

    while(t--){
        cin >> n >> global_max;
        global_min = global_max;
        current_max = global_max;
        current_min = global_min;
        sum = global_max;
        while(--n){
            int x;
            cin >> x;
            sum += x;
            current_max = max(current_max + x, x);
            current_min = min(current_min + x, x);
            global_max = max(global_max, current_max);
            global_min = min(global_min, current_min);
        }
        cout << max(0, max(global_max, sum - global_min)) << "\n";
    }

    return 0;

}