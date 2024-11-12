#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int solve(int k, int n){
    
    int phi = k;

    int temp = k;

    if(temp % 2 == 0){
        phi -= phi / 2;
        temp /= temp & -temp;
    }

    for(int i = 3; i * i <= temp; i += 2){
        if(temp % i == 0){
            phi -= phi / i;
            while(temp % i == 0){
                temp /= i;
            }
        }
    }

    if(temp > 1){
        phi -= phi / temp;
    }

    int result = n / k * phi;

    int mod = n % k;

    for(int i = 1; i <= mod; i++){
        if(gcd(i, k) == 1){
            result++;
        }
    }

    return result;
    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, n;
    cin >> k >> n;

    if(k <= 2){
        cout << n - 1;
        return 0;
    }

    int answer = solve(k, n);

    if(k % 2 == 0){
        answer += solve(k / 2, n / 2);
    }

    cout << answer;

    return 0;
}