#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, m;
    cin >> n >> m;

    vector<long long> arr(n);

    long long x = 1e18;    

    for(long long& a : arr){
        cin >> a;
        x = min(x, a);
    }

    while(x <= m){
        long long sum = 0;
        for(long long& a : arr){
            if(sum + a <= m){
                sum += a;
            }
        }
        m %= sum;
    }

    cout << m;

    return 0;
}