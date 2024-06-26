class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      int n = graph.size();
      vector<int> outDegree(n,0);
      for(int i=0;i<n;i++){
        outDegree[i]=graph[i].size();
      }

      vector<vector<int>> adj(n);

      for(int i=0;i<n;i++){
        for(auto it:graph[i]){
            adj[it].push_back(i);
        }
      }

      queue<int> q;
      for(int i=0;i<n;i++){
        if(outDegree[i]==0){
            q.push(i);
        }
      }

      while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it: adj[node]){
            outDegree[it]--;
            if(outDegree[it]==0){
                q.push(it);
            }
        }
      }

      vector<int> ans;
      for(int i=0;i<n;i++){
        if(outDegree[i]==0){
            ans.push_back(i);
        }
      }
      return ans;
    }
};
