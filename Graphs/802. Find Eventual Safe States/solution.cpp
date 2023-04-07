class Solution {
public:
bool dfs(int node, vector<int> &visited, vector<int> &pathvisited, vector<vector<int>> adj,vector<int> &safenodes){
            visited[node] = 1;
            pathvisited[node] = 1;
            for(auto i: adj[node]){
                if(!visited[i]){
                    if(dfs(i,visited,pathvisited, adj,safenodes)){
                        return true;
                    }
                }
                else if(pathvisited[i]){
                    return true;
                }
            }
            pathvisited[node] = 0;
            safenodes[node] = 1;
            return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V;
        V = graph.size();
        vector<int> visited(V,0);
        vector<int> pathvisited(V,0);
        vector<int> safenodes(V,0);
        vector<int> ans;
        for(int i = 0; i < V;i++){
            if(!visited[i]){
                dfs(i, visited,pathvisited,graph,safenodes);
            }
        }
        for(int i = 0; i < V;i++){
            if(safenodes[i] == 1){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
        
};
