#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    vector<vector<pair<int, int>>> arr(1e5 + 1);

    for(int i = 1; i * i <= 1e5; i++){
        for(int j = 1; i * i + j * j <= 1e5; j++){
            arr[i * i + j * j].push_back(make_pair(i, j));
        }
    }

    while(t--){
        long long x1, y1, x2, y2, w;
        cin >> x1 >> y1 >> x2 >> y2 >> w;
        int answer = 0;
        for(auto& [x, y] : arr[w]){
            if(x * y2 <= x2 * y and x1 * y <= x * y1){
                answer++;
            }
        }
        cout << answer << "\n";
    }

    return 0;
}