#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    if(n == 1){
        cout << 1;
    }else if(n == 2){
        cout << 10;
    }else{

        vector<long long> fib(91);

        fib[1] = 1;

        for(int i = 2; i <= 90; i++){
            fib[i] = fib[i - 1] + fib[i - 2];
        }

        string answer = "";

        while(n > 1){
            int digit = lower_bound(fib.begin(), fib.end(), n + 1) - fib.begin() - 2;
            long long idx = n - (fib[digit + 1] - 1) - 1;
            int zero_padding = digit - 2;
            if(idx){
                zero_padding -= lower_bound(fib.begin(), fib.end(), idx + 1) - fib.begin() - 2;
            }
            string result = "10";
            while(zero_padding--){
                result += '0';
            }
            n = idx;
            answer += result;
        }

        if(n == 1){
            answer += '1';
        }

        cout << answer;

    }

    return 0;
}