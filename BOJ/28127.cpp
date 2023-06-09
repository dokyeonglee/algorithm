#include <iostream>
#include <vector>

using namespace std;

long long sum(long long a, long long d, int floor){
    return floor * a + (floor - 1) * floor / 2 * d;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    while(q--){

        long long a, d, x;
        cin >> a >> d >> x;
        
        int left = 1;
        int right = 2000;

        while(left <= right){
            int mid = (left + right) / 2;
            if(x > sum(a, d, mid - 1)){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        int answer = right;

        cout << answer << " " << x - sum(a, d, answer - 1) << "\n";

    }

    return 0;

}