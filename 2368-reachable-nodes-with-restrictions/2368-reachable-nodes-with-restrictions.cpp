class Solution {
private:
    void dfs(int s, int &n, vector<vector<int>> &adj, vector<bool> &visited, unordered_set<int> &st, int &ans){
        visited[s] = true;
        ans++;
        for(int neigh : adj[s]){
            if(!st.count(neigh) && !visited[neigh]) dfs(neigh, n, adj, visited, st, ans);
        }
    }
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int> st(restricted.begin(), restricted.end());
        vector<bool> visited(n, false);
        //create adjacency list
        vector<vector<int> > adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        //adjacency list created
        int ans = 0;
        dfs(0, n, adj, visited, st, ans);
        return ans; 
    }
};