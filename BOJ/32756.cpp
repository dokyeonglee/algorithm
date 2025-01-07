#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b){
    return b ? gcd(b, a % b) : a;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, d;
    cin >> n >> d;

    long long g = abs(gcd(n, d));

    n /= g;
    d /= g;

    if(d & (d - 1)){
        cout << -1;
    }else{

        long long bit = abs(n) / d;
        char dir = (n > 0 ? 'R' : 'L');
        int cnt = 0;

        string answer;

        while(bit > 0){
            if(bit & 1){
                answer += dir;
            }
            bit >>= 1;
            if(bit){
                cnt++;
                answer += 'U';
            }
        }

        bit = abs(n) % d;

        if(bit){
            answer += string(cnt + 1, 'D');
            while(bit > 0){ 
                if(bit * 2 >= d){
                    answer += dir;
                }
                bit = bit * 2 % d;
                if(bit){
                    answer += 'D';
                }
            }
        }

        cout << answer.size() << "\n";
        cout << answer;

    }

    return 0;
}