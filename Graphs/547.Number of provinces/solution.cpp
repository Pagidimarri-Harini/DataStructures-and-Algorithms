class Solution {
public:
    void dfs(int start, vector<vector<int>> adjlist, vector<int> &visited){
        visited[start] = 1;
        for(auto i:adjlist[start]){
            if(visited[i] == 0)
                dfs(i,adjlist,visited);
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjlist(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1){
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        int nodes = adjlist.size();
        vector<int> visited(nodes,0);
        int count = 0;
        for(int i = 0; i < nodes; i++){
            if(visited[i] == 0){
                dfs(i,adjlist,visited);
                count++;
            }
        }
        return count;
    }
};
