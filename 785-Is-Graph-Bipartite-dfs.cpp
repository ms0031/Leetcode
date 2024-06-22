class Solution {
private:
    bool check(int st,vector<int> &color,vector<vector<int>> &graph,int oldColor){
        color[st]=!oldColor;
            for(auto it : graph[st]){
                if(color[it]==-1){
                    if(check(it,color,graph,color[st])==false){
                        return false;
                    }
                }
                else if(color[it]==color[st]){
                    return false;
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
            if(check(i,color,graph,1)==false){
                return false;
            }
        }}
        return true;
    }
};
