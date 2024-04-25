#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> arr(n);
    for(auto& a : arr){
        cin >> a;
    }

    int left = 0;
    int right = n - 1;

    int answer = 0;

    while(left < right){
        if(arr[left] == arr[right]){
            left++;
            right--;
            continue;
        }
        if(arr[left] < arr[right]){
            arr[left + 1] += arr[left];
            left++;
        }else{
            arr[right - 1] += arr[right];
            right--;
        }
        answer++;
    }

    cout << answer;

    return 0;
}