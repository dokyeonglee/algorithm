#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r;
    cin >> r;
    
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int& a : arr){
        cin >> a;
    }

    int cnt = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] > r){
            if(r + cnt >= arr[i]){
                int temp = arr[i] - r;
                r = arr[i];
                cnt -= temp - 1;
            }
        }else if(arr[i] == r){
            cnt++;
        }else if(arr[i] < r){
            r++;
        }
    }

    cout << r << " " << r + cnt;

    return 0;
}