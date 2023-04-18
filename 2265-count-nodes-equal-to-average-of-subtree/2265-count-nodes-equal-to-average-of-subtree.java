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
    int ans = 0;
    public int averageOfSubtree(TreeNode root) {
        function(root);
        return ans;
    }
    //represent pair of <sum of subtree, count of nodes in subtree>
    Pair<Integer, Integer> function(TreeNode root){
        if(root == null){
            return new Pair<>(0,0);
        }
        //left call
        Pair<Integer, Integer> l = function(root.left);
        //right call
        Pair<Integer, Integer> r = function(root.right);
        
        //condition
        if(root.val == (l.getKey()+r.getKey()+root.val)/(l.getValue()+r.getValue()+1)) ans++;
        
        return new Pair<>(l.getKey()+r.getKey()+root.val, l.getValue()+r.getValue()+1);
    }
}