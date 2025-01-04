#include <vector>
#include <iostream>

using namespace std;

int main(){

    int n, m;

    while(cin >> n >> m){
        bool check = true;
        if(m == 0){
            check = false;
        }else if(n < 2){
            check = (m == 1);
        }else if(n < m){
            long long temp = m;
            for(long long i = 2; i * i <= temp; i++){
                long long cnt = 0;
                while(temp % i == 0){
                    temp /= i;
                    cnt++;
                }
                if(cnt != 0){
                    long long temp2 = i;
                    while(temp2 <= n){
                        cnt -= n / temp2;
                        temp2 *= i;
                    }
                    if(cnt > 0){
                        check = false;
                        break;
                    }
                }
            }
            if(temp > n){
                check = false;
            }
        }
        if(check){
            cout << m << " divides " << n << "!\n";
        }else{
            cout << m << " does not divide " << n << "!\n";
        }
    }

    return 0;

}