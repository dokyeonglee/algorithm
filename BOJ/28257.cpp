#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        long long n;
        cin >> n;

        long long left = 0;
        long long right = 3e8;
        long long floor = 0;
        long long remain = 0;

        while(left <= right){
            long long mid = (left + right) / 2;
            long long sum = 3 * mid * (mid + 1) / 2 - mid;
            if(sum < n){
                floor = mid;
                remain = n - sum;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        int start = 0;

        if(remain <= floor + 1){
            floor = 3 * floor + 1;
            start = 1;
        }else if(remain <= 2 * floor + 1){
            remain -= floor + 1;
            floor = 3 * floor + 2;
            start = 3;
        }else{
            remain -= 2 * floor + 1;
            floor = 3 * floor + 3;
            start = 2;
        }

        long long answer = floor * (floor - 1) / 2 + (remain - 1) * 3 + start;

        cout << answer << "\n";

    }

    return 0;
}