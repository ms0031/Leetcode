class Solution {
bool dfs(int numCourses,vector<vector<int>> &adj,vector<int> &vis,int st,vector<int> &currentVis){
    vis[st]=1;
    currentVis[st]=1;
        for(auto it : adj[st]){
            if(!vis[it]){
            if(dfs(numCourses,adj,vis,it,currentVis)==false){
                return false;
            }
            }
            else if(vis[it]==1 && currentVis[it]==1){
                return false;
            }
    }
    currentVis[st]=0;
    return true;
}
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int n=prerequisites.size();
        vector<int> vis(numCourses,0);
        for(int i=0;i<n;i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> currentVis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
            if(dfs(numCourses,adj,vis,i,currentVis)==false){
            return false;
        }
        }
    }
        return true;
    }
};