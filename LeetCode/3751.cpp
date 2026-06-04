class Solution {
public:
int waviness(int x) {
    string str = to_string(x);
    int result = 0;

    for (int i = 1; i < str.size() - 1; ++i) {
        if ((str[i] > str[i - 1] && str[i] > str[i + 1]) || (str[i] < str[i - 1] && str[i] < str[i + 1])) {
            ++result;
        }
    }

    return result;
}
    int totalWaviness(int num1, int num2) {
        int answer = 0;
        for (int i = num1; i <= num2; ++i) {
            answer += waviness(i);
        }
        return answer;
    }
};