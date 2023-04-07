class Solution {
public:

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adj(V);
        vector<int> indegree(V,0);
      //reverse the graph
        for(int i = 0; i < V; i++){
            for(auto j: graph[i]){
                adj[j].push_back(i);
                indegree[i]++;
            }
        }
        vector<int> safenodes;
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int s = q.front();
            q.pop();
            safenodes.push_back(s);
            for(auto x: adj[s]){
                indegree[x]--;
                if(indegree[x] == 0){
                    q.push(x);
                }
            }
        }
        sort(safenodes.begin(),safenodes.end());
        return safenodes;
        
    }
};
        
