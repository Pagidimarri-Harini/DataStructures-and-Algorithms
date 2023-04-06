class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int maxIsland=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == '1')
                {
                    count++;
                    dfs(i,j,n,m,grid);
                }
            }
        }
        return count;
    }
    void dfs(int i,int j,int n,int m,vector<vector<char>>&grid)
    {
        int x4[]={-1,0,1,0};
        int y4[]={0,1,0,-1};
        if(!(i>=0&&i<n&&j>=0&&j<m))
        {
            return;
        }
        if(grid[i][j]=='0')
        {
            return;
        }
        grid[i][j]='0';
        for(int d=0;d<4;d++)
        {
            int ni=i+x4[d];
            int nj=j+y4[d];
            if(ni>=0&&ni<n&&nj>=0&&nj<m&&grid[ni][nj] == '1')
            {
                dfs(ni,nj,n,m,grid);
            }
        }
        return;
        
    }
};
