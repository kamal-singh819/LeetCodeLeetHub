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
class Pair {
    TreeNode node;
    int num;
    Pair(TreeNode _node, int _num){
        num = _num;
        node = _node;
    }
}
class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        if(root == null) return 0;
        int ans = 0;
        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(root, 0));
        while(!q.isEmpty()){
            int siz = q.size();
            int minn = q.peek().num;
            int firstIndex = 0, lastIndex = 0;
            for(int i=0; i<siz; i++){
                int curr_ind = q.peek().num - minn;
                TreeNode f = q.peek().node;
                q.poll();
                if(i == 0) firstIndex = curr_ind;
                if(i == siz-1) lastIndex = curr_ind;
                
                if(f.left != null) q.offer(new Pair(f.left, 2*curr_ind+1));
                if(f.right != null) q.offer(new Pair(f.right, 2*curr_ind+2));
            }
            ans = Math.max(ans, lastIndex-firstIndex+1);
        }
        return ans;
    }
}