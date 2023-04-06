#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(1){

        int x;
        cin >> x;

        if(cin.eof()){
            break;
        }

        int n;
        cin >> n;

        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        int left = 0;
        int right = n - 1;

        x *= 1e7;

        bool check = false;

        while(left < right){
            int sum = arr[left] + arr[right];
            if(sum < x){
                left++;
            }else if(sum > x){
                right--;
            }else{
                check = true;
                break;
            }
        }

        if(check){
            cout << "yes " << arr[left] << " " << arr[right] << "\n";
        }else{
            cout << "danger\n";
        }

    }

    return 0;
}