class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int x = 0;
        int answer = 0;

        for (int g : gain) {
            x += g;
            answer = max(answer, x);
        }

        return answer;
    }
};