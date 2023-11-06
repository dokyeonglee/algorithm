#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

long long get_lcm(long long a, long long b, long long f){
    long long n = f - a % f;
    return (a + n) * (b + n) / gcd(a + n, b + n);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    if(a == b){
        cout << 1;
    }else{

        if(a > b){
            swap(a, b);
        }

        int diff = b - a;
        int answer = diff;
        long long min_lcm = 1e18;

        for(int i = 1; i * i <= diff; i++){
            if(diff % i == 0){
                long long lcm = get_lcm(a, b, i);
                if(lcm < min_lcm){
                    answer = i - a % i;
                    min_lcm = lcm;
                }else if(lcm == min_lcm){
                    answer = min(answer, i - a % i);
                }
                lcm = get_lcm(a, b, diff / i);
                if(lcm < min_lcm){
                    answer = diff / i - a % (diff / i);
                    min_lcm = lcm;
                }else if(lcm == min_lcm){
                    answer = min(answer, diff / i - a % (diff / i));
                }
            }
        }

        cout << answer;

    }

    return 0;
}