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
    //Post Order Traversal
    pair<int, int> function(TreeNode* root, int &ans){ //int : sum of Subtree, int : count
        if(root == NULL){
            return {0, 0};
        }
        //int : sum of Subtree, int : count of nodes in subtree
        pair<int, int> l = function(root->left, ans);
        pair<int, int> r = function(root->right, ans);
        //root ka value   ,   sum of subtree      , count of nodes in subtree
        if(root->val == (l.first+r.first+root->val)/(l.second+r.second+1)) ans++;
        
        return {l.first+r.first+root->val, l.second+r.second+1};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        function(root, ans);
        return ans;
    }
};