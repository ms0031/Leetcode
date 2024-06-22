class Solution {
private:
    bool bfs(int st,vector<int> &color,vector<vector<int>> &graph){
        queue<int> q;
        q.push(st);
        color[st]=0;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            for(auto it : graph[node]){
                if(color[it]==-1){
                    q.push(it);
                    color[it]=!color[node];
                }
                else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int m= graph[0].size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
            if(bfs(i,color,graph)==false){
                return false;
            }
        }}
        return true;
    }
};
