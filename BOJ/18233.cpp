#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

     int n, p, e;
     cin >> n >> p >> e;

     vector<pair<int, int>> arr(n);
     for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
     }

     if(n < p){
        cout << -1;
        return 0;
     }

     for(int i = 0; i < (1 << n); i++){
         if(__builtin_popcount(i) == p){
            int _min = 0;
            int _max = 0;
            for(int j = 0; j < n; j++){
               if(i & (1 << j)){
                  _min += arr[j].first;
                  _max += arr[j].second;
               }
            }
            if(_min <= e and e <= _max){
               int sum = _min;
               for(int j = 0; j < n; j++){
                  if(i & (1 << j)){
                     int add = 0;
                     if(e > sum){
                        add = min(e - sum, arr[j].second - arr[j].first);
                     }
                     sum += add;
                     cout << arr[j].first + add << " ";
                  }else{
                     cout << "0 ";
                  }
               }
               return 0;
            }
         }
     }

     cout << -1;

    return 0;
}