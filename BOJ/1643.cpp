#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b){
    return b ? gcd(b, a % b) : a;
}

long long length_of_digit(long long x){
    long long result = 0;
    while(x > 0){
        result++;
        x /= 10;
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;

    while(cin >> n){

        long long denominator = n;
        long long numerator = 1;

        for(int i = 1; i < n; i++){
            long long new_denominator = denominator * (n - i);
            long long new_numerator = numerator * (n - i) + denominator;
            long long g = gcd(new_denominator, new_numerator);
            denominator = new_denominator / g;
            numerator = new_numerator / g;
        }

        numerator *= n;

        long long g = gcd(denominator, numerator);

        numerator /= g;
        denominator /= g;

        if(numerator % denominator == 0){
            cout << numerator / denominator << '\n';
        }else{
            long long x = numerator / denominator;
            numerator %= denominator;
            int sz = length_of_digit(x);
            for(int i = 0; i < sz; i++){
                cout << ' ';
            }
            cout << ' ' << numerator << '\n';
            cout << x << ' ';
            sz = length_of_digit(denominator);
            for(int i = 0; i < sz; i++){
                cout << '-';
            }
            cout << '\n';
            sz = length_of_digit(x);
            for(int i = 0; i < sz; i++){
                cout << ' ';
            }
            cout << ' ' << denominator << '\n';
        }

    }

    return 0;
}