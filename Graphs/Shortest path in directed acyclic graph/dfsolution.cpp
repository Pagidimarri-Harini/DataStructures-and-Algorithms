class Solution {
  public:
   void topoSort(vector<int> &distance,int &node, vector<vector<pair<int, int>>> &adjlist) 
	{
	    
	    for(auto j: adjlist[node]){
	        if(distance[node] != INT_MAX)
                distance[j.first] = min(distance[j.first], j.second + distance[node]);
	        topoSort(distance,j.first,adjlist);
	    }
	    return;
	    

	}
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         vector<vector<pair<int, int>>> adjlist(N);
         vector<int> distance(N, INT_MAX);
         distance[0] = 0;
         for(int i = 0; i < M; i++){
             adjlist[edges[i][0]].push_back({edges[i][1], edges[i][2]});
         }
        for(int i = 0; i < N; i++){
            topoSort(distance,i, adjlist);
        }
             
        for(int i = 0; i < N; i++){
            if(distance[i] == INT_MAX){
                distance[i] = -1;
            }
        }
        return distance;
        // code here
    }
};
