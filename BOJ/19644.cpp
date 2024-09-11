#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int ml, mk;
    cin >> ml >> mk;

    int c;
    cin >> c;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    vector<long long> psum(n + 1);

    for(int i = 1; i <= n; i++){
        psum[i] = psum[i - 1];
        int damage = psum[i - 1] - (i > ml ? psum[i - ml] : 0) + mk;
        if(damage < arr[i]){
            if(c-- == 0){
                cout << "NO";
                return 0;
            }
        }else{
            psum[i] += mk;
        }
    }

    cout << "YES";

    return 0;
}