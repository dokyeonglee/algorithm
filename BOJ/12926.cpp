#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, x, a, b;
    cin >> n >> x >> a >> b;

    int q;
    cin >> q;

    vector<int> left(q, 0);
    vector<int> right(q, 1000000006);
    vector<int> query(q);

    for(int i = 0; i < q; i++){
        cin >> query[i];
    }

    map<int, vector<int>> mids;

    long long answer = 0;

    vector<int> result(q);

    while(1){

        for(auto& it : mids){
            it.second.clear();
        }
        mids.clear();

        bool check = false;
        vector<int> temp;

        for(int i = 0; i < q; i++){
            if(left[i] <= right[i]){
                check = true;
                if(mids.count((left[i] + right[i]) / 2) == 0){
                    temp.push_back((left[i] + right[i]) / 2);
                }
                mids[(left[i] + right[i]) / 2].push_back(i);
            }
        }

        if(!check){
            break;
        }

        sort(temp.begin(), temp.end());

        long long now = x;
        vector<int> cnt(temp.size() + 1);

        for(int i = 0; i < n; i++){
            auto it = lower_bound(temp.begin(), temp.end(), now) - temp.begin();
            cnt[it]++;
            now = (now * a + b) % 1000000007;
        }

        for(int i = 1; i < temp.size(); i++){
            cnt[i] += cnt[i - 1];
        }
 
        for(int i = 0; i < temp.size(); i++){
            for(auto& ii : mids[temp[i]]){
                if(query[ii] <= cnt[i] - 1){
                    result[ii] = temp[i];
                    right[ii] = temp[i] - 1;
                }else{
                    left[ii] = temp[i] + 1;
                }
            }
        }

    }

    for(int i = 0; i < q; i++){
        answer += result[i];
    }

    cout << answer;

    return 0;
}