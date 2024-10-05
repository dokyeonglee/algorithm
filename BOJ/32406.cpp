#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> brr(n);

    for(auto& a : arr){
        cin >> a;
    }

    for(auto& b : brr){
        cin >> b;
    }

    int answer = abs(arr[n - 1] + brr[n - 2] - brr[n - 1] - arr[n - 2]);

    for(int i = 0; i < n - 2; i++){
        answer += abs(arr[i] - brr[i]);
    }

    cout << answer;

    return 0;
}