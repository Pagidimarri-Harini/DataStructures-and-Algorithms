class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int xdir[] = {0,0,1,-1};
        int ydir[] = {1,-1,0,0};
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ls(n, vector<int>(m,0));
        vector<vector<int>> visited(n, vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }
        int distance = 0;
        while(!q.empty()){
            int z = q.size();
            for(int i = 0; i < z; i++){
                pair<int, int> x = q.front();
                q.pop();
                ls[x.first][x.second] = distance;
                for(int j = 0; j < 4; j++){
                    int ni = x.first + xdir[j];
                    int nj = x.second + ydir[j];
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m && visited[ni][nj] == 0){
                        q.push({ni,nj});
                        visited[ni][nj] = 1;
                    }
                }
            }

            distance++;
        }
        return ls;

        
    }
};
