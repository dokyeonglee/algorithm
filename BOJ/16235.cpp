#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void spring_and_summer(vector<vector<vector<int>>>& tree, vector<vector<int>>& nutrition){
    
    int n = tree.size();
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            
            if(tree[i][j].size() == 0){
                continue;
            }
            
            sort(tree[i][j].begin(), tree[i][j].end());
            
            int pos = 0;
            int added_nutrition = 0;
            
            for(int k = 0; k < tree[i][j].size(); k++){
                
                if(nutrition[i][j] >= tree[i][j][k]){
                    nutrition[i][j] -= tree[i][j][k];
                    tree[i][j][k]++;
                    pos = k + 1;
                }else{
                    added_nutrition += tree[i][j][k] / 2;
                }
            }
            
            tree[i][j].erase(tree[i][j].begin() + pos, tree[i][j].end());
            nutrition[i][j] += added_nutrition;
        }
    }
    
}

void autumn(vector<vector<vector<int>>>& tree){
    
    int n = tree.size();
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
        	
            if(tree[i][j].size() == 0){
                continue;   
            }
            
            for(int k = 0; k < tree[i][j].size(); k++){
            	
                if(tree[i][j][k] % 5 == 0){
                	
                    for(int x = 0; x < 8; x++){
                        
                        int next_r = i + dr[x];
                        int next_c = j + dc[x];
                        
                        if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= n){
                            continue;
                        }
                        
                        tree[next_r][next_c].push_back(1);
                        
                    }
                }
            }
        }
    }
}

void winter(vector<vector<int>>& nutrition, vector<vector<int>>& A){
    
    int n = nutrition.size();
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            nutrition[i][j] += A[i][j];
        }
    }
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<int>> A(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> A[i][j];
        }
    }
    
    vector<vector<vector<int>>> tree;
    vector<vector<int>> nutrition(n, vector<int>(n, 5));
    
    tree.resize(n, vector<vector<int>>(n));
    
    for(int i = 0; i < m; i++){
        int r, c, age;
        cin >> r >> c >> age;
        tree[r - 1][c - 1].push_back(age);
    }
    
    for(int i = 0; i < k; i++){
        spring_and_summer(tree, nutrition);
        autumn(tree);
        winter(nutrition, A);
    }
    
    int answer = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            answer += tree[i][j].size();
        }
    }
    
    cout << answer << "\n";
    
    return 0;
}