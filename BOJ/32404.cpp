#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> answer(n);

    int temp = n;

    for(int i = n - 2 + n % 2; i >= 0; i -= 2){
        answer[i] = temp--;
    }

    for(int i = 1; i < n; i += 2){
        answer[i] = temp--;
    }

    for(auto& x : answer){
        cout << x << " ";
    }

    return 0;
}