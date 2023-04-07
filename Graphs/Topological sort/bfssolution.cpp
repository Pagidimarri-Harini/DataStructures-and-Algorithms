class Solution
{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        vector<int> indegree(V,0);
    
        for(int i = 0; i < V; i++){
            for(auto m: adj[i])
                indegree[m]++;
            
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
                indegree[x]--;
                if(indegree[x] == 0){
                    q.push(x);
                }
            }
        }
        return topo;

	}
};
