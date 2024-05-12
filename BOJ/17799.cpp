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
    }

    sort(arr.begin(), arr.end());

    int left = 0;
    int right = n - 1;

    int answer = 0;

    while(left <= right){
        answer++;
        if(arr[left] + arr[right] <= c){
            left++;
            right--;
        }else{
            right--;
        }
    }

    cout << answer;

    return 0;
}