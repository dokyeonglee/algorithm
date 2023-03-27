#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, l;
    cin >> n >> k >> l;

    vector<long long> hamburger(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> hamburger[i];
    }

    vector<int> cola(n + l + 5);
    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        cola[x]++;
        cola[x + l]--;
    }

    for(int i = 1; i < cola.size(); i++){
        cola[i] += cola[i - 1];
    }

    sort(hamburger.begin() + 1, hamburger.end(), greater<>());
    sort(cola.begin() + 1, cola.begin() + n + 1, greater<>());

    long long answer = 0;

    for(int i = 1; i <= n; i++){
        if(cola[i] <= 30){
            answer += hamburger[i] / (1ll << cola[i]);
        }
    }


    cout << answer;

    return 0;
}