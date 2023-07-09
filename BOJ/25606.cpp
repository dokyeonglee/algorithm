#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, m, q;
    cin >> n >> m >> q;

    vector<long long> arr(n + 1);
    vector<long long> psum(110005);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        psum[i + 1] += m;
        psum[i + 1 + arr[i] / m] -= m;
        psum[i + 1 + arr[i] / m] += arr[i] % m;
        psum[i + 1 + arr[i] / m + 1] -= arr[i] % m;
        arr[i] += arr[i - 1];
    }

    for(int i = 1; i <= n; i++){
        psum[i] += psum[i - 1];
    }

    for(int i = 1; i <= n; i++){
        psum[i] += psum[i - 1];
    }

    for(int i = 0; i < q; i++){
        int c, x;
        cin >> c >> x;
        if(c == 1){
            cout << arr[x] - psum[x] << "\n";
        }else{
            cout << psum[x] - psum[x - 1] << "\n";
        }
    }

    return 0;
}