#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> p(m);
    for(int& x : p){
        cin >> x;
    }

    vector<int> psum(n + 5);
    
    for(int i = 1; i < m; i++){
        if(p[i - 1] < p[i]){
            psum[p[i - 1]]++;
            psum[p[i]]--;
        }else{
            psum[p[i]]++;
            psum[p[i - 1]]--;
        }
    }

    for(int i = 1; i <= n; i++){
        psum[i] += psum[i - 1];
    }

    long long answer = 0;

    for(int i = 1; i < n; i++){
        long long a, b, c;
        cin >> a >> b >> c;
        answer += min(a * psum[i], b * psum[i] + c);
    }

    cout << answer;

    return 0;
}