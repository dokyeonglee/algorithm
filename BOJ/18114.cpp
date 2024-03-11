#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, c;
    cin >> n >> c;

    vector<int> arr(n);
    for(int& a : arr){
        cin >> a;
        if(a == c){
            cout << 1;
            return 0;
        }
    }

    sort(arr.begin(), arr.end());

    int left = 0;
    int right = n - 1;

    while(left < right){
        int temp = c - (arr[left] + arr[right]);
        if(temp == 0){
            cout << 1;
            return 0;
        }else if(temp < 0){
            right--;
        }else{
            auto it = lower_bound(arr.begin() + left + 1, arr.begin() + right, temp);
            if(it != arr.begin() + right and *it == temp){
                cout << 1;
                return 0;
            }
            left++;
        }

    }

    cout << 0;

    return 0;
}