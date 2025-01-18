#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int>& score, int k, int m){
    for(int i = 1; i < k; i++){
        if(score[i] >= score[k]){
            m--;
        }
    }
    for(int i = k + 1; i <= 4; i++){
        if(score[i] > score[k]){
            m--;
        }
    }
    return m == 1;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, m;
    cin >> n >> k >> m;

    vector<int> score(5);
    vector<vector<int>> cnt(5, vector<int>(5));

    for(int i = 0; i < n; i++){
        int a1, a2, a3, a4, s1, s2, s3, s4;
        cin >> a1 >> a2 >> a3 >> a4 >> s1 >> s2 >> s3 >> s4;
        score[a1] += s1;
        score[a2] += s2;
        score[a3] += s3;
        score[a4] += s4;
        cnt[a1][1]++;
        cnt[a2][2]++;
        cnt[a3][3]++;
        cnt[a4][4]++;
    }

    for(int d4 = -100; d4 <= 100; d4++){
        for(int d3 = d4; d3 <= 100; d3++){
            for(int d2 = d3; d2 <= 100; d2++){
                int d1 = -(d2 + d3 + d4);
                if(d1 < d2 or d1 > 100){
                    continue;
                }
                for(int i = 1; i <= 4; i++){
                    score[i] += d1 * cnt[i][1] + d2 * cnt[i][2] + d3 * cnt[i][3] + d4 * cnt[i][4]; 
                }
                if(check(score, k, m)){
                    cout << d1 << " " << d2 << " " << d3 << " " << d4;
                    return 0;
                }
                for(int i = 1; i <= 4; i++){
                    score[i] -= d1 * cnt[i][1] + d2 * cnt[i][2] + d3 * cnt[i][3] + d4 * cnt[i][4]; 
                }
            }
        }
    }

    cout << -1;

    return 0;

}