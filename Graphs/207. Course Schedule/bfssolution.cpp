class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& graph) {
        vector<int> indegree(V,0);
        vector<vector<int>> adj(V);
        for(auto i: graph){
            adj[i[1]].push_back(i[0]);
        }
        for(int i = 0; i < V; i++){
            for(auto m: adj[i])
                indegree[m]++;
            
        }
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int s = q.front();
            q.pop();
            V--;
            for(auto x: adj[s]){
                indegree[x]--;
                if(indegree[x] == 0){
                    q.push(x);
                }
            }
        }
        if(V == 0)
            return true;
        return false;
        
    }
};
