#include <iostream>
#include <vector>

using namespace std;

int cnt(int n, int k){
    n++;
    return n / (1 << (k + 1)) * (1 << k) + max(0, n % (1 << (k + 1)) - (1 << k));
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int k = 0;

    while((1 << k) < n){
        k++;
    }

    vector<int> answer(n);

    vector<int> guess(n);
    for(int j = 0; j < n; j++){
        guess[j] = j;
    }

    for(int i = 0; i < 2; i++){

        cout << "? ";
        for(auto& g : guess){
            cout << g << " ";
        }
        cout << endl;

        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            answer[j] |= ~guess[j] & x;
        }

        for(int j = 0; j < n; j++){
            guess[j] = (1 << k) - j - 1;
        }

        for(int j = k - 1; j >= 0; j--){
            int x = cnt((1 << k) - 1, j) - cnt((1 << k) - n - 1, j) - cnt(n - 1, j);
            for(int idx = 0; idx < x; idx++){
                guess[idx] ^= (1 << j);
            }
        }

    }

    cout << "! ";
    for(int& x : answer){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}