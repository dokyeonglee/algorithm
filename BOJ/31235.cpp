#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int& a : arr){
        cin >> a;
    }

    int answer = 1;
    int max_value = arr[0];
    int idx = 0;

    for(int i = 1; i < n; i++){
        if(max_value <= arr[i]){
            max_value = arr[i];
            answer = max(answer, i - idx);
            idx = i;
        }
    }

    answer = max(answer, n - idx);

    cout << answer;

    return 0;
}