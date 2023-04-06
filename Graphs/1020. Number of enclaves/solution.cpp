class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid,int n, int m){
        int x4[]={-1,0,1,0};
        int y4[]={0,1,0,-1};
        if(!(i>=0&&i<n&&j>=0&&j<m))
        {
            return;
        }
        if(grid[i][j]==0)
        {
            return;
        }
        grid[i][j]=0;
        for(int d=0;d<4;d++)
        {
            int ni=i+x4[d];
            int nj=j+y4[d];
            if(ni>=0&&ni<n&&nj>=0&&nj<m&&grid[ni][nj]==1)
            {
                dfs(ni,nj,grid,n,m);
            }
        }
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((i==0||j==0||i==n-1||j==m-1) && grid[i][j] == 1){
                    dfs(i,j,grid,n,m);
                }
            }
            
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
        
    }
};
