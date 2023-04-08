class Solution {
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
        queue<int> q;
        q.push(0);
        ans++;
        visited[0] = true;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            if(adj[front].size() == 0) continue;
            for(int neigh : adj[front]){
                if(!st.count(neigh) && !visited[neigh]){
                    q.push(neigh);
                    ans++;
                    visited[neigh] = true;
                }
            }
        }
        return ans; 
    }
};