#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> prime(n);
    for(int i = 0; i < n; i++){
        cin >> prime[i];
    }

    long long k;
    cin >> k;

    long long answer = 0;

    for(int i = 0; i < prime.size(); i++){
        long long p = prime[i];
        while(k >= p){
            answer += k / p;
            p *= prime[i];
        }
    }

    cout << answer;

    return 0;
}