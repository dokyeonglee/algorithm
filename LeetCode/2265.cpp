/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int, int> dfs(TreeNode* node, int& answer) {
        if (node == nullptr) {
            return {0, 0};
        }

        auto [left_sum, left_count] = dfs(node->left, answer);
        auto [right_sum, right_count] = dfs(node->right, answer);
        int sum = left_sum + right_sum + node->val;
        int cnt = left_count + right_count + 1;

        if (sum / cnt == node->val) {
            ++answer;
        }
        
        return {sum, cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        int answer = 0;
        dfs(root, answer);
        return answer;
    }
};/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int, int> dfs(TreeNode* node, int& answer) {
        if (node == nullptr) {
            return {0, 0};
        }

        auto [left_sum, left_count] = dfs(node->left, answer);
        auto [right_sum, right_count] = dfs(node->right, answer);
        int sum = left_sum + right_sum + node->val;
        int cnt = left_count + right_count + 1;

        if (sum / cnt == node->val) {
            ++answer;
        }
        
        return {sum, cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        int answer = 0;
        dfs(root, answer);
        return answer;
    }
};