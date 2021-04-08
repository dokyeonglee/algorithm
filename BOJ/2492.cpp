#include <iostream>
#include <vector>

using namespace std;

int count_iron(vector<pair<int, int>>& iron_pos, int x, int y, int k){
    int result = 0;
    for(pair<int, int> p : iron_pos){
        if(x <= p.first and p.first <= x + k
            and y <= p.second and p.second <= y + k){
                result++;
            }
    }
    return result;
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, t, k;
    cin >> n >> m >> t >> k;

    vector<pair<int, int>> iron_pos(t);
    for(int i = 0; i < t; i++){
        cin >> iron_pos[i].first >> iron_pos[i].second;
    }
    
    
    int answer_max = 0;
    int answer_x;
    int answer_y;
    
    for(int i = 0; i < t; i++){
        
        int x = min(iron_pos[i].first, n - k);
        
        for(int j = 0; j < t; j++){
            
            int y = min(iron_pos[j].second, m - k);
            int cnt = count_iron(iron_pos, x, y, k);
            
            if(answer_max < cnt){
                answer_max = cnt;
                answer_x = x;
                answer_y = y + k;
            }
            
        }
    }
    
    cout << answer_x << " " << answer_y << '\n';
    cout << answer_max;
    
    return 0;
}