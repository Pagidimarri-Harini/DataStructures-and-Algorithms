class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<int> distance(V, INT_MAX);
        distance[S] = 0;
        pq.push({0,S});
        while(!pq.empty()){
            pair<int, int> x = pq.top();
            pq.pop();
            for(auto ad: adj[x.second]){
                if(distance[ad[0]] > ad[1] + x.first){
                    distance[ad[0]] = ad[1] + x.first;
                    pq.push({distance[ad[0]], ad[0]});
                }
            }
        }
        return distance;
    }
};
