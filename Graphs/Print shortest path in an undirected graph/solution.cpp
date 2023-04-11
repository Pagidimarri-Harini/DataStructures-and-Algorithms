class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto ad : edges)
        {
            adj[ad[0]].push_back({ad[1], ad[2]});
            adj[ad[1]].push_back({ad[0], ad[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        vector<int> distance(n+1,INT_MAX);
        vector<int> parent(n+1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
        distance[1] = 0;
        pq.push({0,1});
        while(!pq.empty()){
            pair<int, int> x = pq.top();
            pq.pop();
            for(auto ad: adj[x.second]){
                if(distance[ad.first] > distance[x.second] + ad.second){
                    distance[ad.first] = distance[x.second] + ad.second;
                    parent[ad.first] = x.second;
                    pq.push({distance[ad.first],ad.first});
                }
            }
            
        }
        if(distance[n] == INT_MAX){
            return {-1};
        }
        int node = n;
        vector<int> ans;
        while(parent[node] != node){
            ans.push_back(node);
            node = parent[node];
            
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
        // Code here
    }
};
