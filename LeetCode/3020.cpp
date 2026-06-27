class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> umap;
        for (int num : nums) {
            ++umap[num];
        }

        int answer = umap[1] + umap[1] % 2 - 1;
        umap.erase(1);

        for (auto& it : umap) {
            long long temp = it.first;
            int cnt = 0;
    
            auto target = umap.find(temp);
            while (target != umap.end() && target->second > 1) {
                ++cnt;
                temp *= temp;
                target = umap.find(temp);
            }

            if (target == umap.end()) {
                answer = max(answer, 2 * cnt - 1);
            } else {
                answer = max(answer, 2 * cnt + 1);
            }
        }

        return answer;
    }
};