class Solution {
public:
    static constexpr int left_block = 0b111100;
    static constexpr int middle_block = 0b11110000;
    static constexpr int right_block = 0b1111000000;
    static constexpr int side_blocks = 0b1100001100;

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> seats;
        for (auto& s : reservedSeats) {
            seats[s[0]] |= 1 << s[1];
        }

        int answer = (n - seats.size()) * 2;
        for (auto& it : seats) {
            int reserved = it.second;
            if ((reserved & middle_block) == 0) {
                ++answer;
                if ((reserved & side_blocks) == 0) {
                    ++answer;
                }
            } else if ((reserved & left_block) == 0 || (reserved & right_block) == 0) {
                ++answer;
            }
        }

        return answer;
    }
};