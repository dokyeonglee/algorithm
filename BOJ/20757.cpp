#include <iostream>
#include <vector>

using namespace std;

int find_parent(vector<int>& parent, int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    parent[y] = x;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    int arr[225][225];

    while(t--){

        int n;
        cin >> n;

        vector<int> parent(n + 1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }

        int answer = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int x;
                cin >> x;
                if(x == 1 and i != j){
                    answer++;
                    arr[i][j] = 1;
                }else{
                    arr[i][j] = 0;
                }
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                if(arr[i][j]){
                    if(find_parent(parent, i) != find_parent(parent, j)){
                        union_parent(parent, i, j);
                        answer--;
                    }else{
                        answer -= 2;
                    }
                }
            }
        }

        cout << answer << "\n";

    }

    return 0;
}