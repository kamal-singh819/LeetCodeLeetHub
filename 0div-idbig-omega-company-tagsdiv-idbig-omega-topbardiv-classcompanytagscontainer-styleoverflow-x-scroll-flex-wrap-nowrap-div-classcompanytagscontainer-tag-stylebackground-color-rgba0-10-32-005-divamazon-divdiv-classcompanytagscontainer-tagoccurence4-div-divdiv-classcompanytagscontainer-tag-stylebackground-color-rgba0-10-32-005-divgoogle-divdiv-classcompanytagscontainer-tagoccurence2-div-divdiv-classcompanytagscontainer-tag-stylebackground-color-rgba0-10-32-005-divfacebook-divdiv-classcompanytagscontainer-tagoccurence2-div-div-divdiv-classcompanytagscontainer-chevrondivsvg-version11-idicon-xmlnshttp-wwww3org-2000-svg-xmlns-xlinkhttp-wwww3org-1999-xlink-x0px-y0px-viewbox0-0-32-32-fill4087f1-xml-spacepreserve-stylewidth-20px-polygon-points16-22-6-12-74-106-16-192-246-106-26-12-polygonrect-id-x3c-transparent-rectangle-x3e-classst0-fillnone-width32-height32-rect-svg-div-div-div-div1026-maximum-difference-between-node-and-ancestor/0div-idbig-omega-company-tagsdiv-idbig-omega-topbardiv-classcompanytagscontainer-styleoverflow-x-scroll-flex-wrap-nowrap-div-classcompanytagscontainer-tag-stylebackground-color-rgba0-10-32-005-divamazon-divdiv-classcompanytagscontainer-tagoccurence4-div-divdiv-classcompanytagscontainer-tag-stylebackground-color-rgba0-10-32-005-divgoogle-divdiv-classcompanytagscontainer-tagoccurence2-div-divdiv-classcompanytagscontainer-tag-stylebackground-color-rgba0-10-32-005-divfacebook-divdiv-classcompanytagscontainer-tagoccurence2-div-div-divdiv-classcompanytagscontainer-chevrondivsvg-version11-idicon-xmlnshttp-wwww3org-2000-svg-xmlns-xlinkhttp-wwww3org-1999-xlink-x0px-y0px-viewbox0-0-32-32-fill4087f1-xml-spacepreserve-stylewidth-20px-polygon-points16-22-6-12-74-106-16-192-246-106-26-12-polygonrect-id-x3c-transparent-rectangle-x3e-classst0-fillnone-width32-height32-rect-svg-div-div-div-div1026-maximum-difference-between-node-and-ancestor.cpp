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
    private:
    int findMaxDiff(TreeNode* root, int minNum, int maxNum){
        if(root == NULL)
            return maxNum-minNum;

        minNum = min(minNum, root->val);
        maxNum = max(maxNum, root->val);

        return max(findMaxDiff(root->left, minNum, maxNum), findMaxDiff(root->right, minNum, maxNum));    
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int minNum = 100001;
        int maxNum = -1;
        return findMaxDiff(root, minNum, maxNum);
        
    }
};