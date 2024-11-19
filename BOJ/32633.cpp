#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b){
    return b ? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b){
    return a * b / gcd(a, b);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    long long l;
    cin >> l;

    vector<int> arr(n);

    for(auto& a : arr){
        cin >> a;
    }

    vector<bool> check(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        check[i] = x;
    }

    long long answer = 1;

    for(int i = 0; i < n; i++){
        if(check[i]){
            answer = lcm(answer, arr[i]);
        }
        if(answer > l){
            cout << -1;
            return 0;
        }
    }

    for(int i = 0; i < n; i++){
        if(!check[i]){
            if(answer % arr[i] == 0){
                cout << -1;
                return 0;
            }
        }
    }

    cout << answer;

    return 0;
}