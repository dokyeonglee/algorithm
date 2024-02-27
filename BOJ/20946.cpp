#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    vector<long long> arr;

    for(long long i = 2; i * i <= n; i++){
        while(n % i == 0){
            arr.push_back(i);
            n /= i;
        }
    }

    if(n > 1){
        arr.push_back(n);
    }

    if(arr.size() == 1){
        cout << -1;
        return 0;
    }

    if(arr.size() % 2 == 1){
        long long temp = arr.back();
        arr.pop_back();
        arr.back() *= temp;
    }

    for(int i = 0; i < arr.size(); i += 2){
        cout << arr[i] * arr[i + 1] << " ";
    }

    return 0;
}