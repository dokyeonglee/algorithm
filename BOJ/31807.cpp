#include <iostream>
#include <vector>

using namespace std;

int get_t(vector<int>& arr){

    vector<int> f(arr.size());

    for(int i = 1, j = 0; i < arr.size(); i++){
        while(j and arr[i] != arr[j]){
            j = f[j - 1];
        }
        if(arr[i] == arr[j]){
            f[i] = ++j;
        }
    }

    return arr.size() - f.back();

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int t = get_t(arr);

    vector<long long> integral(t + 1);

    for(int i = 1; i <= t; i++){
        integral[i] = integral[i - 1] + arr[i - 1];
    }

    int a, b;
    cin >> a >> b;

    if(a < 0){
        int move = (a % t + t) % t - a;
        a += move;
        b += move;
    }

    long long answer = (b / t - a / t) * integral[t] + integral[b % t] - integral[a % t];
    
    cout << answer;

    return 0;
}