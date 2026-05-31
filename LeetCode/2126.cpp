class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        vector<int> cnt(1e5 + 1);
        for (int a : asteroids) {
            ++cnt[a];
        }

        long long current_mass = mass;
        for (int i = 1; i <= 1e5; ++i) {
            if (cnt[i]) {
                if (current_mass < i) {
                    return false;
                }
                current_mass += 1ll * cnt[i] * i;
            }
        }
        
        return true;
    }
};