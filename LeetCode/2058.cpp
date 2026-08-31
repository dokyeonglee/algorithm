/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return {-1, -1};
        }

        int idx = 1;
        int first_critical_idx = -1;
        int prev_critical_idx = -1;
        int prev_val = head->val;
        int min_distance = INT_MAX;

        ListNode* node = head->next;
        while (node->next) {
            int val = node->val;
            if ((val > prev_val && val > node->next->val) || (val < prev_val && val < node->next->val)) {
                if (first_critical_idx == -1) {
                    first_critical_idx = idx;
                } else {
                    min_distance = min(min_distance, idx - prev_critical_idx);
                }
                prev_critical_idx = idx;
            }
            prev_val = val;
            node = node->next;
            ++idx;
        }

        if (min_distance == INT_MAX) {
            return {-1, -1};
        }

        return {min_distance, prev_critical_idx - first_critical_idx};
    }
};