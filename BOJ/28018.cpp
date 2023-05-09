#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(1000005);

    for(int i = 0; i < n; i++){
        int s, e;
        cin >> s >> e;
        arr[s]++;
        arr[e]--;
    }

    for(int i = 1; i <= 1000000; i++){
        arr[i] += arr[i - 1];
    }

    int m;
    cin >> m;

    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        cout << arr[x] << "\n";
    }

    return 0;
}