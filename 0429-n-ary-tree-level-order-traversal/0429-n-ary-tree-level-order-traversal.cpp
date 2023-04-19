/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int siz = q.size();
            vector<int> level;
            while(siz--){
                auto f = q.front();
                q.pop();
                level.push_back(f->val);
                //only one change is this------
                for(auto nextlevel : f->children){ //children is vector of node's children
                    q.push(nextlevel);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};