#include <iostream>
#include <vector>

using namespace std;

char solve(vector<int>& moo, int n){
    
    int idx = 0;
    while(moo[++idx] < n);

    if(moo[idx - 1] + 1 == n){
        return 'm';
    }else if(moo[idx - 1] + idx + 2 >= n){
        return 'o';
    }else{
        return solve(moo, n - moo[idx - 1] - idx - 2);
    }

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> moo(30);
    moo[1] = 3;

    for(int i = 2; i < moo.size(); i++){
        moo[i] = 2 * moo[i - 1] + i + 2;
    }

    int n;
    cin >> n;

    cout << solve(moo, n);

    return 0;
}