class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        for(int i = 0; i < graph.size(); i++){
            queue<int> q;
            if(color[i] == -1)
                q.push(i);
                color[i] = 0;
            while(!q.empty()){
                int x = q.front();
                q.pop();
                for(auto y: graph[x]){
                    if(color[y] == -1){
                        color[y] = (!color[x]);
                        q.push(y);
                    }
                    else if(color[y] == color[x]){
                        return false;
                    }
                }
            }
        }
        return true;
        
    }
};
