class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto x: p){
            adjList[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            topo.push_back(x);
            for(auto ad: adjList[x]){
                indegree[ad]--;
                if(indegree[ad] == 0){
                    q.push(ad);

                }
            }
        }
        if(topo.size() == numCourses){
            return topo;
        }
        return {};

        
    }
};
