#include <iostream>
#include <vector>

using namespace std;

int digit_sum(long long x){
    int result = 0;
    while(x){
        result += x % 10;
        x /= 10;
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    long long dst = stoll(str);

    long long src = dst - str.size() * 9;

    for(long long i = src; i < dst; i++){
        long long sum = i + digit_sum(i);
        if(sum == dst){
            cout << i;
            return 0;
        }
    }

    cout << 0;

    return 0;
}