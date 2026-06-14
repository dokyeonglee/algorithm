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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;
        ListNode* reversed_head = nullptr;
        ListNode* curr = slow;
        while (curr != nullptr) {
            ListNode* next_node = curr->next;
            curr->next = reversed_head;
            reversed_head = curr;
            curr = next_node;
        }

        int answer = 0;
        while (head != reversed_head) {
            answer = max(answer, head->val + reversed_head->val);
            head = head->next;
            reversed_head = reversed_head->next;
        }

        return answer;
    }
};