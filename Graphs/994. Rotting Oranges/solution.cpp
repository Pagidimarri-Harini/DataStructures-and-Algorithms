class Solution {
public:
    int orangesRotting(vector<vector<int>>& v) {
        int x4[] = {-1,0,1,0};
        int y4[] = {0, 1, 0,-1};
        int days = 0;
        int n = v.size();
        int m = v[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(v[i][j] == 2){
                    q.push({i,j});
                }
                
            }
        }
        while(!q.empty()){
            int z = q.size();
            int flag = 0;
            for(int i = 0; i < z; i++){
                pair<int, int> p = q.front();
                q.pop();
                for(int d= 0; d < 4; d++){
                    int ni = p.first + x4[d];
                    int nj = p.second + y4[d];
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m && v[ni][nj] == 1){
                        flag = 1;
                        q.push({ni, nj});
                        v[ni][nj] = 2;
                    }
                }

            }
            if(flag == 1)
                days += 1;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(v[i][j] == 1){
                    days = -1;
                }
            }
        }

        return days;
        
    }
};
