#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto& a : arr){
        cin >> a;
    }

    for(int& a : arr){
        int x;
        cin >> x;
        a -= x;
    }

    int answer = abs(arr[0]);

    for(int i = 1; i < n; i++){
        if(arr[i] * arr[i - 1] > 0){
            answer += max(0, abs(arr[i]) - abs(arr[i - 1]));
        }else{
            answer += abs(arr[i]);
        }
    }

    cout << answer;

    return 0;
}