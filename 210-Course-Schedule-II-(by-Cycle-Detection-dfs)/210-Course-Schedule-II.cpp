class Solution {
private:
    bool dfs(int st,vector<vector<int>> &adj,vector<int> &vis,vector<int> &currVis,vector<int> &ans){
        vis[st]=1;
        currVis[st]=1;
        for(auto it : adj[st]){
            if(!vis[it]){
            if(dfs(it,adj,vis,currVis,ans)==false){
                return false;
            }
            }
            else if(currVis[it]){
                return false;
            }
        }
    
    currVis[st]=0;
    ans.push_back(st);
    return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>> adj(numCourses);

       for(auto it : prerequisites){
            adj[it[0]].push_back(it[1]);
       }
    vector<int> vis(numCourses,0);
    vector<int> currVis(numCourses,0);
    vector<int> ans;
    vector<int> emptyVector;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,currVis,ans)==false){
                    return emptyVector;
                }
            }
        }
      return ans;
    }
};