class Solution {
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V,0);
    
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
            return false;
        return true;
    }
};
