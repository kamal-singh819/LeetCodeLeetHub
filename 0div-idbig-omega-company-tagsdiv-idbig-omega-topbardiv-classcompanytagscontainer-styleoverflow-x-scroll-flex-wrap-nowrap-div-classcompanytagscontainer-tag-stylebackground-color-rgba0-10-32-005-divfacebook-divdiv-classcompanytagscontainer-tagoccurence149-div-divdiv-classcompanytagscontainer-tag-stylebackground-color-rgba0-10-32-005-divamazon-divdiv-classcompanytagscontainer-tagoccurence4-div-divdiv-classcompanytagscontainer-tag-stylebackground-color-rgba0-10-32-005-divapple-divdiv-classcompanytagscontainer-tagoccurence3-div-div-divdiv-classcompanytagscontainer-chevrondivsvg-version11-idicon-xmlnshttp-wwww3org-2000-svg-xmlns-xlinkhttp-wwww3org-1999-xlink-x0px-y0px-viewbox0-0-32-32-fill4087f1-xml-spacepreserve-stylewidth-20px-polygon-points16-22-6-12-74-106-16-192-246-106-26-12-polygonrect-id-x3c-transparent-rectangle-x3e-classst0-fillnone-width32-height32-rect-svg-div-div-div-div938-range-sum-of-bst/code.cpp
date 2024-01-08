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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        stack<TreeNode*> st;
        TreeNode* temp = root;
        while(temp != NULL || !st.empty()){
            while(temp!=NULL){
                st.push(temp);
                temp = temp->left;
            }
            temp = st.top();
            st.pop();
            if(temp->val >=low && temp->val <= high)
                ans += temp->val;
            if(temp->val >high)
                break;
            temp = temp->right;
        }
        return ans;
    }
};
