class Solution {
public:
    void dfs(int node, int parent, vector<int> &visited,vector<int> adj[], int number[], int reach[], vector<vector<int>> &bridges,int time) {
            visited[node] = 1;
            number[node] = reach[node] = time;
            time++;
            for (auto ad : adj[node]) {
                if (ad == parent) continue;
                if (visited[ad] == 0) {
                    dfs(ad, node, visited, adj, number, reach, bridges, time);
                    reach[node] = min(reach[ad], reach[node]);
                    if (reach[ad] > number[node]) {
                        bridges.push_back({ad, node});
                    }
                }
                else {
                    reach[node] = min(reach[node], reach[ad]);
                }
            }
        }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for (auto it : connections) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n, 0);
        int number[n];
        int reach[n];
        vector<vector<int>> bridges;
        dfs(0, -1, visited, adj, number, reach, bridges,1);
        return bridges;
        
    }
};
