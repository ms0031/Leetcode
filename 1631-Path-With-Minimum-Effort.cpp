class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dis(n,vector<int>(m,1e9));
        dis[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({0,{0,0}});
            int delRow[]={-1,0,1,0};
            int delCol[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.top().second.first;
            int col=q.top().second.second;
            int d = q.top().first;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=delRow[i]+row;
                int nc=delCol[i]+col;
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int newEffort = max(d,abs(heights[row][col]-heights[nr][nc]));
                    if(newEffort<dis[nr][nc]){
                        q.push({newEffort,{nr,nc}});
                        dis[nr][nc]=newEffort;
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};
