class Solution {
private:
    void dfs(pair<int,int> st,vector<vector<int>>& vis,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vis[st.first][st.second]=1;
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nrow=st.first+row[i];
                int ncol=st.second+col[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                        dfs({nrow,ncol},vis,grid);
                }
            }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0)); 
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==1 ){
                dfs({i,0},vis,grid);
            }
            if(!vis[i][m-1] && grid[i][m-1]==1){
               dfs({i,m-1},vis,grid); 
            }
        }

        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]==1){
               dfs({0,j},vis,grid); 
            }
            if(!vis[n-1][j] && grid[n-1][j]==1){
               dfs({n-1,j},vis,grid); 
            }
        }

        int count=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                   count++;
                }
            }
        }
        return count;
        
    }
};