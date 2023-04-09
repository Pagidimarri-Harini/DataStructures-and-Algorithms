class Solution{
    public:
    vector<int> topoSort(int V, vector<vector<int>> adj) 
	{
        int indegree[V] = {0};
    
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
    string findOrder(string dict[], int N, int K) {
        string ans = "";
        vector<vector<int>> adjlist(K);
        for(int i = 0; i < N-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int n = min(s1.size(), s2.size());
            for(int j = 0; j < n; j++){
                if(s1[j] != s2[j]){
                    adjlist[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        vector<int> res = topoSort(K, adjlist);
        for(int i = 0; i < res.size(); i++){
            ans = ans+ char(res[i]+'a');
        }
        return ans;
        
    }
};
