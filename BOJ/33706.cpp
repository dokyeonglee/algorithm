#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<bool> check(n + 1);

    int cnt = 0;
    
    while(m--){
        int a, b;
        cin >> a >> b;
        if(!check[b]){
            cnt++;
            check[b] = true;
        }
    }

    if(cnt == n - 1){
        cout << "YES";
    }else{
        cout << "NO";
    }


    return 0;

}