#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;

    while(tc--){

        int n, t;
        cin >> n >> t;

        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);
        vector<int> d(n);
        vector<int> e(n + 1);

        for(int i = 0; i < n; i++){
            cin >> a[i] >> b[i] >> c[i] >> d[i];
        }

        for(int i = 0; i <= n; i++){
            cin >> e[i];
        }

        string answer = "NO\n";

        int left = 0;
        int right = t;

        while(left <= right){
            int mid = (left + right) / 2;
            int now = mid + e[0];
            for(int i = 0; i < n; i++){
                now = max(now, c[i]);
                int x = (now - c[i]) / a[i];
                if(!(c[i] + a[i] * x <= now and now + d[i] <= c[i] + a[i] * x + b[i])){
                    x++;
                }
                now = max(now, c[i] + a[i] * x) + d[i];
                now += e[i + 1];
            }
            if(now == t){
                answer = "YES\n";
                break;
            }
            if(now <= t){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        cout << answer;
    }

    return 0;
}