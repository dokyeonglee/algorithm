#include <iostream>
#include <vector>

using namespace std;

bool possilbe(int e, int em, int m, int mh, int h, int x){
    if(e + em < x){
        return false;
    }
    em -= max(0, x - e);
    if(em + m + mh < x){
        return false;
    }
    mh -= max(0, x - em - m);
    return mh + h >= x;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int e, em, m, mh, h;
    cin >> e >> em >> m >> mh >> h;

    int left = 0;
    int right = mh + h;

    int answer = 0;

    while(left <= right){
        int mid = (left + right) / 2;
        if(possilbe(e, em, m, mh, h, mid)){
            answer = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    cout << answer;

    return 0;
}