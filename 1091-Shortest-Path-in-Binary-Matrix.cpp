class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();

        vector<vector<int>> dis(n,vector<int>(m,1e9));
        if(grid[0][0]==0)dis[0][0]=1;
        else dis[0][0]=-1;
        queue<pair<int,int>> q;
        if(grid[0][0]==0)q.push({0,0});
        while(!q.empty()){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int i=-1;i<=1;i++){
                    for(int j=-1;j<=1;j++){
                        int delRow= row+i;
                        int delCol= col+j;
                if(delRow>=0 && delRow<n && delCol>=0 && delCol<m && grid[delRow][delCol]==0){
                    if(dis[delRow][delCol]>dis[row][col]+1){
                        dis[delRow][delCol]=dis[row][col]+1;
                        q.push({delRow,delCol});
                    }
                }
                    }
                }
            }

        if(dis[n-1][m-1]==1e9)return -1;

        return dis[n-1][m-1];
        }
};
