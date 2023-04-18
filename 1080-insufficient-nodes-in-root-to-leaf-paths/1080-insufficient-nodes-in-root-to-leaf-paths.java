/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode sufficientSubset(TreeNode root, int limit) {
        int sum = 0;
        return function(root, limit, sum);
    }
    
    TreeNode function(TreeNode root, int limit, int sum){
        if(root == null) return null;
        if(root.left == null && root.right == null){
            if(sum+root.val < limit) return null;
            else return root;
        }
        //call left
        TreeNode l = function(root.left, limit, sum+root.val);
        //call right
        TreeNode r = function(root.right, limit, sum+root.val);
        
        if(l == null) root.left = null;
        if(r == null) root.right = null;
        if(l == null && r == null) return null;
        return root;
    }
}