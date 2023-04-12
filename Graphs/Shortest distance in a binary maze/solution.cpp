// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,pair<int, int> destination) {
        int xdir[] = {0,0,-1,1};
        int ydir[] = {-1,1,0,0};
        int n = grid.size();
        int m = grid[0].size();
        if(source == destination){
            return 0;
        }
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> distance(n, vector<int>(m,INT_MAX));
        q.push({{source.first, source.second}, 0});
        distance[source.first][source.second] = 0;
        while(!q.empty()){
            pair<pair<int, int>, int> x = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int newx = x.first.first + xdir[i];
                int newy = x.first.second + ydir[i];
                if(newx >= 0 && newx < n && newy >= 0 && newy < m && grid[newx][newy] == 1){
                    if(distance[newx][newy] > 1 + x.second){
                        distance[newx][newy] = 1 + x.second;
                        if(newx == destination.first && newy == destination.second){
                            return distance[newx][newy];
                        }
                        q.push({{newx, newy},distance[newx][newy]});
                    }
                }
            }
        }
        return -1;
    }
};
