class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adjList(n);
        for(auto x: roads){
            adjList[x[1]].push_back({x[0],x[2]});
            adjList[x[0]].push_back({x[1],x[2]});
            
        }
         priority_queue<pair<long long,int> , vector<pair<long long,int>>, greater<pair<long long,int>> > pq;
        vector<long long> distance(n, LONG_MAX);
        vector<int> ways(n, 0);
        distance[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        while(!pq.empty()){
            pair<long long, int> x = pq.top();
            pq.pop();
            for(auto ad: adjList[x.second]){
                if(distance[ad.first] > ad.second + x.first){
                    distance[ad.first] = ad.second + x.first;
                    ways[ad.first] = ways[x.second];
                    pq.push({distance[ad.first], ad.first});
                }
                else if(distance[ad.first] == ad.second + x.first){
                    ways[ad.first] = (ways[ad.first]+ways[x.second])%1000000007;
                }
            }
        }
        return ways[n-1] % 1000000007;

        
    }
};
