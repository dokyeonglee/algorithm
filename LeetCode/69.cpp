class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x;
        int answer = x;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (x / mid >= mid) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return answer;
    }
};