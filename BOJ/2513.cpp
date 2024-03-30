#include <iostream>
#include <vector>


using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, s;
    cin >> n >> k >> s;

    vector<int> arr(1e5 + 1);

    for(int i = 0; i < n; i++){
        int x, p;
        cin >> x >> p;
        arr[x] = p;
    }

    int answer = 0;

    for(int i = 0; i < s; i++){
        if(arr[i]){
            int a = (arr[i] + k - 1) / k;
            answer += (s - i) * a;
            arr[i + 1] -= (k - arr[i] % k) % k;
        }
    }

    for(int i = 1e5; i > s; i--){
        if(arr[i]){
            int a = (arr[i] + k - 1) / k;
            answer += (i - s) * a;
            arr[i - 1] -= (k - arr[i] % k) % k;
        }
    }

    answer *= 2;

    cout << answer;

    return 0;
}