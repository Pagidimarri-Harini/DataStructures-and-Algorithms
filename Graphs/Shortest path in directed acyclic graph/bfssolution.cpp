class Solution {
  public:
   vector<int> topoSort(int V, vector<vector<pair<int,int>>> adj) 
	{
        int indegree[V] = {0};
    
        for(int i = 0; i < V; i++){
            for(auto m: adj[i])
                indegree[m.first]++;
            
        }
        vector<int> topo;
        queue<int> q;
        stack<int> st;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int s = q.front();
            q.pop();
            topo.push_back(s);
            for(auto x: adj[s]){
                indegree[x.first]--;
                if(indegree[x.first] == 0){
                    q.push(x.first);
                }
            }
        }
        return topo;

	}
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         vector<vector<pair<int, int>>> adjlist(N);
         vector<int> distance(N, INT_MAX);
         distance[0] = 0;
         for(int i = 0; i < M; i++){
             adjlist[edges[i][0]].push_back({edges[i][1], edges[i][2]});
         }
         vector<int> order = topoSort(N, adjlist);
         for(auto i: order){
             for(auto j: adjlist[i]){
                 if(distance[i] != INT_MAX)
                    distance[j.first] = min(distance[j.first], j.second + distance[i]);
                 
             }
             
        }
        for(int i = 0; i < N; i++){
            if(distance[i] == INT_MAX){
                distance[i] = -1;
            }
        }
        return distance;
    }
};
