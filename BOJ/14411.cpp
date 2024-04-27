#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> height(5e6 + 5);

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        height[x / 2] = max(height[x / 2], y);
    }
    

    long long answer = 0;

    for(int i = 5e6; i > 0; i--){
        height[i] = max(height[i], height[i + 1]);
        answer += 2 * height[i];
    }

    cout << answer;

    return 0;
}