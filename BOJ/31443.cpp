#include <iostream>
#include <vector>

using namespace std;

long long pow(long long a, long long n, long long mod){
    if(n == 0){
        return 1;
    }
    auto result = pow(a, n / 2, mod);
    result = result * result % mod;
    if(n % 2 == 1){
        result = result * a % mod;
    }
    return result;
}

int make_three_by_one(int n, int m){
    return max(n / 3 * m + (m / 3) * (n % 3), m / 3 * n + (n / 3) * (m % 3));
}

long long solve(int n, int m, int mod){

    if(n == 1 and m == 4 or n == 4 and m == 1){
        return 4;
    }

    if(n < 3 and m < 3){
        return n * m;
    }

    int three_by_one = make_three_by_one(n, m);
    int remain = n * m - three_by_one * 3;

    if(remain == 1){
        return pow(3, three_by_one - 1, mod) * 4 % mod;
    }else if(remain == 2){
        return pow(3, three_by_one, mod) * 2 % mod;
    }else if(remain == 4){
        return pow(3, three_by_one, mod) * 4 % mod;
    }else{
        return pow(3, three_by_one, mod);
    }

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    const int mod = 1e9 + 7;

    cout << solve(n, m, mod) << " ";


    return 0;
    
}