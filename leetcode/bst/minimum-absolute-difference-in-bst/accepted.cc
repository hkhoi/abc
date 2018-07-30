/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<TreeNode*, int> leftmost;
    unordered_map<TreeNode*, int> rightmost;
    int minDiff = INT_MAX;
    
    /**
    * Runtime   O(n)
    * Space     O(n)
    */
    void dfs(TreeNode* root)
    {
        // Get the leftmost
        if (root->left != nullptr) {
            getMinimumDifference(root->left);
            leftmost[root] = leftmost[root->left];
        } else {
            leftmost[root] = root->val;
        }
        
        // Get the rightmost
        if (root->right != nullptr) {
            getMinimumDifference(root->right);
            rightmost[root] = rightmost[root->right];
        } else {
            rightmost[root] = root->val;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return;
        }
        
        int leftVal = root->left != nullptr ? abs(rightmost[root->left] - root->val) : INT_MAX;
        int rightVal = root->right != nullptr ? abs(leftmost[root->right] - root->val) : INT_MAX;
        minDiff = min(minDiff, min(leftVal, rightVal));        // OMFG, bug here!!
    }
    
public:
    int getMinimumDifference(TreeNode* root)
    {
        dfs(root);
        return minDiff;
    }
};
