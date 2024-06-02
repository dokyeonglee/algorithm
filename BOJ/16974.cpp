#include <iostream>
#include <vector>

using namespace std;

long long solve(int level, long long x){

    //(level - 1)의 햄버거 레이의수, 패티수
    long long burger = (1ll << (level + 1)) - 3;
    long long patty = (1ll << level) - 1;

    if(level == 0){
        return 1;
    }else if(x == 1){
        return 0;
    }else if(x <= burger + 1){
        return solve(level - 1, x - 1);
    }else if(x == burger + 2){
        return patty + 1;
    }else{
        return patty + 1 + solve(level - 1, x - burger - 2);
    }

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, x;
    cin >> n >> x;

    cout << solve(n, x);

    return 0;
}