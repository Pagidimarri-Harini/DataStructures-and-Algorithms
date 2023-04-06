class Solution {
    private:
    bool bfs(int src, vector<int> adj[], int vis[]){
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src,-1});
        while(!q.empty()){
            int val = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto ad: adj[val]){
                if(vis[ad] == 0){
                    q.push({ad,val});
                    vis[ad] = 1;
                }
                else if(ad != parent){
                    return true;
                }
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
                if(bfs(i,adj,vis)){
                    return true;
                }
            }
        }
        return false;
        
        // Code here
    }
};
