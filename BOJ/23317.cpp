#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    vector<vector<int>> comb(31, vector<int>(31));
    comb[0][0] = 1;
    comb[1][0] = 1;
    comb[1][1] = 1;
    for(int i = 2; i <= 30; i++){
        comb[i][0] = 1;
        for(int j = 1; j <= i; j++){
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }   
    }
    
    int n;
    cin >> n;
    
    int m;
    cin >> m;
    
    vector<pair<int, int>> arr(m);
    for(int i = 0; i < m; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    arr.push_back(make_pair(0, 0));
    sort(arr.begin(), arr.end());
    
    long long answer = 1;
    for(int i = 0; i < m; i++){
    	if(arr[i + 1].second < arr[i].second){
    		answer = 0;
    		break;
    	}
        answer *= comb[arr[i + 1].first - arr[i].first][arr[i + 1].second - arr[i].second];
    }
    
    answer *= 1ll << (n - 1 - arr.back().first);
    
    cout << answer;
    
    return 0;
}