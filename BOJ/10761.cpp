#include <iostream>
#include <vector>

using namespace std;

const int B = 0;
const int E = 1;
const int S = 2;
const int I = 3;
const int G = 4;
const int O = 5;
const int M = 6;

long long answer = 0;

void dfs(vector<vector<int>>& cnt, vector<int>& perm, int depth){

    if(depth == perm.size()){

        int bessie = perm[B] + perm[E] + perm[S] + perm[S] + perm[I] + perm[E];
        int goes = perm[G] + perm[O] + perm[E] + perm[S];
        int moo = perm[M] + perm[O] + perm[O];

        if(bessie % 7 == 0 or goes % 7 == 0 or moo % 7 == 0){
            long long result = 1;
            for(int i = 0; i < 7; i++){
                result = result * cnt[i][perm[i]];
            }
            answer += result;
            return; 
        }

    }

    for(int i = 0; i < 7; i++){
        if(cnt[depth][i]){
            perm[depth] = i;
            dfs(cnt, perm, depth + 1);
        }
    }

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> cnt(26, vector<int>(7));

    int n;
    cin >> n;

    while(n--){
        char c;
        int x;
        cin >> c >> x;
        int idx = -E;
        if(c == 'B'){
            idx = B;
        }else if(c == 'E'){
            idx = E;
        }else if(c == 'S'){
            idx = S;
        }else if(c == 'I'){
            idx = I;
        }else if(c == 'G'){
            idx = G;
        }else if(c == 'O'){
            idx = 5;
        }else if(c == 'M'){
            idx = 6;
        }
        cnt[idx][(x % 7 + 7) % 7]++;
    }

    vector<int> perm(7);

    dfs(cnt, perm, 0);

    cout << answer;

    return 0;
}