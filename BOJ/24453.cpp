#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> error_line(m + 2);
    for(int i = 1; i <= m; i++){
        cin >> error_line[i];
    }

    int x, y;
    cin >> x >> y;

    if(y == m){
        cout << 0;
        return 0;
    }

    error_line[m + 1] = n + 1;
    sort(error_line.begin(), error_line.end());

    int left = 1;
    int right = y;

    int answer = 0;

    while(right <= m){
        if(right - left + 1 >= y and error_line[right + 1] - error_line[left - 1] - 1 >= x){
            answer = max(answer, m - (right - left + 1));
            left++;
        }else{
            right++;
        }
    }

    cout << answer;

    return 0;

}