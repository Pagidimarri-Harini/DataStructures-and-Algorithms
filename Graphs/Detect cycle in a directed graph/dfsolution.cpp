class Solution {
  public:
      bool dfs(int node, int visited[], int pathvisited[], vector<int> adj[]){
            visited[node] = 1;
            pathvisited[node] = 1;
            for(auto i: adj[node]){
                if(!visited[i]){
                    if(dfs(i,visited,pathvisited, adj)){
                        return true;
                    }
                }
                else if(pathvisited[i]){
                    return true;
                }
            }
            pathvisited[node] = 0;
            return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int visited[V] = {0};
        int pathvisited[V] = {0};
        for(int i = 0; i < V;i++){
            if(!visited[i]){
                if(dfs(i, visited,pathvisited,adj)){
                    return true;
                }
            }
        }
        return false;

    }
};
