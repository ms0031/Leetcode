class Solution {
private:
    void bfs(pair<int,int> st,vector<vector<int>> &vis,vector<vector<char>> &ans,vector<vector<char>>& board){
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>> q;
        q.push({st});
        vis[st.first][st.second]=1;
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        while(!q.empty()){
            pair<int,int> node=q.front();
            ans[node.first][node.second]='O';
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=node.first+row[i];
                int ncol=node.second+col[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && board[nrow][ncol]=='O'){
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
                }
            }
            
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<char>> ans(n,vector<char>(m,0));

        for(int j=0;j<m;j++){
                if(board[0][j]=='O' && !vis[0][j]){
                    bfs({0,j},vis,ans,board);
                }
        }

         for(int i=0;i<n;i++){
                if(board[i][0]=='O' && !vis[i][0]){
                    bfs({i,0},vis,ans,board);
                }
        }

         for(int j=0;j<m;j++){
                if(board[n-1][j]=='O' && !vis[n-1][j]){
                    bfs({n-1,j},vis,ans,board);
                }
        }

         for(int i=0;i<n;i++){
                if(board[i][m-1]=='O' && !vis[i][m-1]){
                    bfs({i,m-1},vis,ans,board);
                }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    ans[i][j]='X';
                }
            }
        }
       board = ans;
    }
};