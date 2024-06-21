class Solution {
private:
    void bfs(queue<pair<pair<int,int>,int>> &q,vector<vector<int>>& mat,vector<vector<int>> &vis,vector<vector<int>> &dis){

        int n= mat.size();
        int m = mat[0].size();
        vis[q.front().first.first][q.front().first.second]=1;
        while(!q.empty()){
            pair<int,int> node = q.front().first;
            int level = q.front().second;
            dis[node.first][node.second]=level;
            q.pop();
            int row[]={-1,0,1,0};
            int col[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int delrow=node.first+row[i];
                int delcol=node.second+col[i];
                if(delrow>=0 && delrow<n && delcol>=0 && delcol<m && vis[delrow][delcol]==0 && mat[delrow][delcol]==1){
                    q.push({{delrow,delcol},level+1});
                    vis[delrow][delcol]=1;
                }  
                }
            }
        }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0 && !vis[i][j]){
                    q.push({{i,j},0});
                }
            }
        }
        bfs(q,mat,vis,dis);
        return dis;
    }
};