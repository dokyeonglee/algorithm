#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, q;
    cin >> n >> m >> k >> q;

    vector<int> limit(m + 1);
    for(int i = 1; i <= m; i++){
        cin >> limit[i];
    }

    vector<vector<int>> growth_days(n + 1);
    for(int i = 1; i <= k; i++){
        int x;
        cin >> x;
        growth_days[x].push_back(i);
    }

    vector<int> answer(k + 1);

    while(q--){
        int child1, child2, x;
        cin >> child1 >> child2 >> x;
        if(growth_days[child1].size() + growth_days[child2].size() >= limit[x]){
            int left = 1;
            int right = k;
            int idx = 0;
            while(left <= right){
                int mid = (left + right) / 2;
                int child1_height = upper_bound(growth_days[child1].begin(), growth_days[child1].end(), mid) - growth_days[child1].begin();
                int child2_height = upper_bound(growth_days[child2].begin(), growth_days[child2].end(), mid) - growth_days[child2].begin();
                if(child1_height + child2_height >= limit[x]){
                    idx = mid;
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            answer[idx]++;
        }
    }

    for(int i = 1; i <= k; i++){
        answer[i] += answer[i - 1];
        cout << answer[i] << "\n";
    }



    return 0;

}