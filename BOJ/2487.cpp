#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        arr[x] = i;
    }

    int answer = 1;

    vector<bool> check(n + 1);

    for(int i = 1; i <= n; i++){
        if(!check[i]){
            int cnt = 1;
            int temp = arr[i];
            while(temp != i){
                cnt++;
                check[temp] = true;
                temp = arr[temp];
            }
            answer = answer * (cnt / gcd(cnt, answer));
        }
    }

    cout << answer;

    return 0;
}