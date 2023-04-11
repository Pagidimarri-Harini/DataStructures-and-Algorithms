class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>>s;
        vector<int> distance(V, INT_MAX);
        distance[S] = 0;
        s.insert({0,S});
        while(!s.empty()){
            pair<int, int> x = *(s.begin());
            s.erase(x);
            for(auto ad: adj[x.second]){
                if(distance[ad[0]] > ad[1] + x.first){
                    if(distance[ad[0]] != INT_MAX){
                        s.erase({distance[ad[0]], ad[0]});
                    }
                    distance[ad[0]] = ad[1] + x.first;
                    s.insert({distance[ad[0]], ad[0]});
                }
            }
        }
        return distance;
    }
};
