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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return nullptr;
        }

        int cnt = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            ++cnt;
        }

        if (k % cnt == 0) {
            return head;
        }

        k %= cnt;

        ListNode* fast = head;
        for (int i = 0; i < k; ++i) {
            fast = fast->next;
        }

        ListNode* slow = head;
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        fast->next = head;
        head = slow->next;
        slow->next = nullptr;

        return head;
    }
};