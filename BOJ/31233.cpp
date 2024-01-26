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

    if(n == 2){
        cout << min(arr[0], arr[1]);
        return 0;
    }

    int answer = 0;

    for(int i = 1; i < n - 1; i++){
        int median;
        int x = min(arr[i], arr[i + 1]);
        int y = max(arr[i], arr[i + 1]);
        if(arr[i - 1] >= y){
            median = y;
        }else if(arr[i - 1] <= x){
            median = x;
        }else{
            median = arr[i - 1];
        }
        answer = max(answer, median);
    }

    cout << answer;

    return 0;
}