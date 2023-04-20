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
    int widthOfBinaryTree(TreeNode* root) {
        //use Level Order Traversal
        //use queue of pair of Node and its index
        if(root == NULL) return 0;
        int ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while(!q.empty()){
            int siz = q.size();
            int minn = q.front().second; //minimum index at this level for finding children's indexes
            long long firstIndex, lastIndex; //ans will be (lastIndex-firstIndex+1) at any level
            for(int i=0; i<siz; i++){
                long long curr_ind = q.front().second-minn;
                TreeNode* f = q.front().first;
                q.pop();
                if(i == 0) firstIndex = curr_ind;
                if(i == siz-1) lastIndex = curr_ind;
                //push left into queue
                if(f->left) q.push({f->left, (long long)2*curr_ind+1});
                if(f->right) q.push({f->right, (long long)2*curr_ind+2});
            }
            int res = lastIndex-firstIndex+1;
            ans = max(ans, res);
        }
        return ans;
    }
};