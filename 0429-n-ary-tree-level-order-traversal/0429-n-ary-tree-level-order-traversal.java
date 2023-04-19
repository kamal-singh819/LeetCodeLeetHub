/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> ans = new ArrayList<>();
        if(root == null) return ans;
        
        Queue<Node> q = new LinkedList<>();
        q.offer(root);
        while(q.size() > 0){
            int siz = q.size();
            List<Integer> level = new ArrayList<>();
            
            while(siz-- > 0){
                Node f = q.poll(); //get front of queue
                level.add(f.val);
                //push all children of 'f' node
                for(Node nl : f.children){
                    q.offer(nl);
                }
            }
            ans.add(new ArrayList<>(level));
        }
        return ans;
    }
}