#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int w, h, k;
    cin >> w >> h >> k;
    
    vector<vector<int>> arr(h + 5, vector<int>(w + 5));
    vector<vector<int>> diamond(h + 5, vector<int>(w + 5));
    
    for(int i = 0; i < k; i++){
        int c;
        cin >> c;
        if(c == 1){
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1++, y1++, x2++, y2++;
            arr[y1][x1]++;
            arr[y1][x2 + 1]--;
            arr[y2 + 1][x1]--;
            arr[y2 + 1][x2 + 1]++;
        }else{
            int x, y, r;
            cin >> x >> y >> r;
            x += 2;
            y += 2;
            diamond[y - r][x]++;
            diamond[y - r + 1][x]++;
            diamond[y + r + 1][x]++;
            diamond[y + r + 2][x]++;
            diamond[y + 1][x + r + 1]--;
            diamond[y + 1][x + r]--;
            diamond[y + 1][x - r - 1]--;
            diamond[y + 1][x - r]--;
        }
    }
    
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    }
    
    for(int i = 2; i < diamond.size(); i++){
        for(int j = 1; j < diamond[0].size() - 1; j++){
            diamond[i][j] += diamond[i - 1][j - 1] + diamond[i - 1][j + 1] - diamond[i - 2][j];
        }
    }
    
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if((arr[i][j] + diamond[i + 1][j + 1]) % 2){
                cout << "#";
            }else{
                cout << ".";
            }
        }
        cout << "\n";
    }
    

    return 0;
}
