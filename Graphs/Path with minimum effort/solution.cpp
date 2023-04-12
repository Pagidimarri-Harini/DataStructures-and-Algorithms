class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        int n = grid.size();
        int m = grid[0].size();
        int xdir[] = {-1,1,0,0};
        int ydir[] = {0,0,-1,1};
        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
        q.push({0, {0, 0}});
        distance[0][0] = 0;
        while(!q.empty()){
            auto x = q.top();
            q.pop();
            if(x.second.first == n-1 and x.second.second == m-1){
                return x.first;
            }
            for(int i = 0; i < 4; i++){
                int newx = x.second.first + xdir[i];
                int newy = x.second.second + ydir[i];
                if(newx >= 0 && newx < n && newy >= 0 && newy < m){
                    int diff = max(x.first, abs(grid[newx][newy]- grid[x.second.first][x.second.second]));
                    if(distance[newx][newy] > diff){
                        distance[newx][newy] = diff;
                        q.push({distance[newx][newy],{newx, newy}});
                    }
                }
            }
        }
        return 0;
        
    }
};
