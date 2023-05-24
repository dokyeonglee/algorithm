    #include <iostream>
    #include <queue>

    using namespace std;

    int main(){

        ios_base::sync_with_stdio(0);
        cin.tie(0);

        int n, m;
        cin >> n >> m;

        vector<long long> arr(n + 1);
        for(long long i = 1; i <= n; i++){
            cin >> arr[i];
        }
        
        int p;
        cin >> p;

        vector<vector<pair<int, long long>>> diff(n + 1);
        priority_queue<pair<long long, int>> pq;

        for(int i = 0; i < p; i++){
            long long a, b, t;
            cin >> a >> b >> t;
            arr[b] += t;
            diff[a].push_back(make_pair(b, t));
        }

        for(int i = 1; i <= n; i++){
            pq.push(make_pair(-arr[i], i));
        }
        
        vector<bool> check(n + 1);

        long long answer = 0;

        while(m > 0){
            long long now = pq.top().second;
            pq.pop();
            if(check[now]){
                continue;
            }
            check[now] = true;
            answer = max(answer, arr[now]);
            for(auto e : diff[now]){
                if(check[e.first]){
                    continue;
                }
                arr[e.first] -= e.second;
                pq.push(make_pair(-arr[e.first], e.first));
            }
            m--;
        }

        cout << answer;
        
        return 0;
    }