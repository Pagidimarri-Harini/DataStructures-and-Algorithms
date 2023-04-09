class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<vector<int>> adjlist(N);
        queue<int> q;
        q.push(src);
        vector<int> distance(N,INT_MAX);
        for(auto i: edges){
            adjlist[i[0]].push_back(i[1]);
            adjlist[i[1]].push_back(i[0]);
        }
        distance[src] = 0;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto i: adjlist[x]){
                if(distance[i] > distance[x] + 1){
                    distance[i] = distance[x] + 1;
                    q.push(i);
                }
            }
            
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
