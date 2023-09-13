#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b){
    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> level(405);
    for(int i = 0; i < n; i++){
        int h;
        cin >> h;
        level[h]++;
        level[h + k]--;
    }

    for(int i = 1; i < 200; i++){
        level[i] += level[i - 1];
    }

    vector<int> monster(m);
    for(int i = 0; i < m; i++){
        cin >> monster[i];
    }

    vector<int> target(201);

    for(int i = 1; i < 200; i++){
        int _max = 0;
        int idx = 0;
        for(int j = 0; j < m; j++){
            if(monster[j] <= i and _max < monster[j]){
                _max = monster[j];
                idx = j;
            }
        }
        target[i] = idx;
    }

    long long origin = 0;

    for(int i = 1; i < 200; i ++){
        origin += target[i] * level[i];
    }

    long long answer = origin;
    int x = 1;
    int y = 2;

    for(int i = 0; i < m; i++){
        for(int j = i + 1; j < m; j++){
            long long sum = 0;
            for(int k = 1; k < 200; k++){
                sum += level[k] * min(target[k], i + abs(target[k] - j));
            }
            if(answer > sum){
                answer = sum;
                x = i + 1;
                y = j + 1;
            }
        }
    }

    cout << x << " " << y << "\n";
    cout << origin - answer;

    return 0;
}