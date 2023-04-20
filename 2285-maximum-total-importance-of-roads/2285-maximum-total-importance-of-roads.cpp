class Solution {
public:
    static bool comp(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;
        //create adjacency list
        vector<vector<int>> adj(n);
        for(auto road : roads){
            adj[road[0]].push_back(road[1]);
            //take as a one side road, otherwise you can return ans/2;
        }
        //adjacency is created
        //create a vector of pairs which holds node and its degree as pair
        vector<pair<int, int>> nodeDeg(n, {0,0});
        for(int i=0; i<roads.size(); i++){
            int x = roads[i][0];
            int y = roads[i][1];
            nodeDeg[x].first = x;
            nodeDeg[x].second++; //update degree
            nodeDeg[y].first = y;
            nodeDeg[y].second++; //update degree
        }
        //sort the vector pair according to degree
        sort(nodeDeg.begin(), nodeDeg.end(), comp);
        
        unordered_map<int, int> mp; //holds node with assigned number to node
        for(int i=0; i<n; i++){
            mp[nodeDeg[i].first] = (i+1);
        }
        //now use adjacency list to calculate ans
        for(int j=0; j<n; j++){
            vector<int> neigh = adj[j];
            for(int i=0; i<neigh.size(); i++){
                ans += (mp[j] + mp[neigh[i]]);
            }
        }
        return ans;
    }
};