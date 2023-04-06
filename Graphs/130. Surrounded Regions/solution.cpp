class Solution {
public:
    void dfs(int n, int m, vector<pair<int, int>> &p, int i, int j, vector<vector<char>> &grid){
        int x4[]={-1,0,1,0};
        int y4[]={0,1,0,-1};
        if(!(i>=0&&i<n&&j>=0&&j<m))
        {
            return;
        }
        if(grid[i][j]=='X')
        {
            return;
        }
        grid[i][j]='X';
        p.push_back({i,j});
        for(int d=0;d<4;d++)
        {
            int ni=i+x4[d];
            int nj=j+y4[d];
            if(ni>=0&&ni<n&&nj>=0&&nj<m&&grid[ni][nj]=='O')
            {
                dfs(n,m,p,ni,nj,grid);
            }
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<pair<int, int>> p;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((i == 0 || j == 0 || i == n-1 || j == m-1) && board[i][j] == 'O'){
                    dfs(n,m,p,i,j, board);
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        for(auto x: p){
            // cout << x.first << x.second << endl;
            board[x.first][x.second] = 'O';
        }
        

        
    }
};
