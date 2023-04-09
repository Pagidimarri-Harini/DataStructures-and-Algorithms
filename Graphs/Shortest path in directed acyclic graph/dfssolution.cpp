class Solution {
  public:
   void topoSort(stack<int> &s, vector<int> &visited, int node, vector<vector<pair<int, int>>> &adjlist) 
	{
	    visited[node] = 1;
	    for(auto i: adjlist[node]){
	        if(!visited[i.first]){
	            topoSort(s,visited,i.first,adjlist);
	        }
	    }
	    s.push(node);
	    

	}
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         vector<vector<pair<int, int>>> adjlist(N);
         stack<int> s;
         vector<int> distance(N, INT_MAX);
         distance[0] = 0;
         for(int i = 0; i < M; i++){
             adjlist[edges[i][0]].push_back({edges[i][1], edges[i][2]});
         }
        vector<int> visited(N);
        for(int i = 0; i < N; i++){
            if(!visited[i]){
                topoSort(s, visited, i, adjlist);
            }
        }
        
        while(!s.empty()){
            int x = s.top();
            s.pop();
            for(auto j: adjlist[x]){
                if(distance[x] != INT_MAX)
                    distance[j.first] = min(distance[j.first], j.second + distance[x]);
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
