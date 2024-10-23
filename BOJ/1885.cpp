#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    if(k == 1){
        cout << n + 1;
    }else{

        vector<int> check((k + 31) / 32);

        int answer = 1;
        int cnt = 0;

        while(n--){

            int x;
            cin >> x;

            if(!(check[x / 32] & (1 << (x % 32)))){
                check[x / 32] |= (1 << (x % 32));
                if(++cnt == k){
                    cnt = 0;
                    answer++;
                    fill(check.begin(), check.end(), 0);
                }
            }
            
        }

        cout << answer;

    }

    return 0;
}