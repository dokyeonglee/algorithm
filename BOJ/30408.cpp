#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool solve(map<long long, bool>& mp, long long n, long long m){

    if(n == 1){
        return m == 1;
    }

    if(n == m){
        return true;
    }
    
    if(mp.count(n)){
        return mp[n];
    }

    return mp[n] = (solve(mp, n / 2, m) | solve(mp, n - n / 2, m));

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, m;
    cin >> n >> m;

    map<long long, bool> mp;

    if(solve(mp, n, m)){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}