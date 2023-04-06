class Solution {
    private:
    bool dfs(int src, int parent, vector<int> adj[], int vis[]){
        vis[src] = 1;
        for(auto x: adj[src]){
            if(!vis[x]){
                if(dfs(x,src,adj,vis)){
                    return true;
                }
            }else if(x != parent){
                return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i,-1,adj,vis)){
                    return true;
                }
            }
        }
        return false;
        
        // Code here
    }
};
