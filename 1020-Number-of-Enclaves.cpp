class Solution {
private:
    void bfs(pair<int,int> st,vector<vector<int>>& ans,vector<vector<int>>& vis,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({st});
        vis[st.first][st.second]=1;
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        while(!q.empty()){
            pair<int,int> node=q.front();
            ans[node.first][node.second]=0;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=node.first+row[i];
                int ncol=node.second+col[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
                }
            }
            
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans=grid;
        
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==1 ){
                bfs({i,0},ans,vis,grid);
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i][m-1] && grid[i][m-1]==1){
               bfs({i,m-1},ans,vis,grid); 
            }
        }

        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]==1){
               bfs({0,j},ans,vis,grid); 
            }
        }

        for(int j=0;j<m;j++){
            if(!vis[n-1][j] && grid[n-1][j]==1){
               bfs({n-1,j},ans,vis,grid); 
            }
        }
        int count=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ans[i][j]==1){
                   count++;
                }
            }
        }
        return count;
        
    }
};