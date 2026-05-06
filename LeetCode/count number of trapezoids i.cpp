class Solution {
public:
    const int MOD = 1e9 + 7;

    int countTrapezoids(vector<vector<int>>& points) {
        vector<int> arr;
        arr.reserve(points.size());

        for (auto& p : points) {
            arr.push_back(p[1]);
        }

        sort(arr.begin(), arr.end());

        long long answer = 0;
        long long sum = 0;
        long long cnt = 0;
        long long sides = 0;
        int prev = arr[0];
        for (int x : arr) {
            if (prev == x) {
                ++cnt;
            } else {
                sides = cnt * (cnt - 1) / 2;
                answer += sum * sides % MOD;
                sum += sides;
                answer %= MOD;
                sum %= MOD;
                prev = x;
                cnt = 1;
            }
        }

        sides = 1ll * cnt * (cnt - 1) / 2;
        answer += sum * sides % MOD;
        answer %= MOD;

        return answer;
    }
};