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
    public int amountOfTime(TreeNode root, int start) {
        //we need node of start in the Tree
        //here we need child to parent also, so first find this relationship 
        Map<TreeNode, TreeNode> parent = new HashMap<>();
        TreeNode target = assignParent(root, parent, start);


        int ans = 0; //no of minutes 
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        Map<TreeNode, Boolean> visited = new HashMap<>();
        q.offer(target);
        visited.put(target, true);
        while(!q.isEmpty()){
            int siz = q.size();
            boolean flag = false;
            for(int i=0; i<siz; i++){
                TreeNode curr = q.poll();
                if(curr.left != null && visited.get(curr.left) == null){
                    visited.put(curr.left, true);
                    q.offer(curr.left);
                    flag = true;
                }
                if(curr.right != null && visited.get(curr.right) == null){
                    visited.put(curr.right, true);
                    q.offer(curr.right);
                    flag = true;
                }
                if(parent.get(curr) != null && visited.get(parent.get(curr)) == null){
                    visited.put(parent.get(curr), true);
                    q.offer(parent.get(curr));
                    flag = true;
                }
            }
            if(flag == true) ans++;
        }
        return ans;
    }

    private TreeNode assignParent(TreeNode root, Map<TreeNode, TreeNode> parent, int start){
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        TreeNode target = new TreeNode(-1);
        q.offer(root);
        while(!q.isEmpty()){
            TreeNode curr = q.poll();
            if(curr.val == start) target = curr; //make node of start

            if(curr.left != null){
                parent.put(curr.left, curr);
                q.offer(curr.left);
            }
            if(curr.right != null){
                parent.put(curr.right, curr);
                q.offer(curr.right);
            }
        }
        return target;
    }
}