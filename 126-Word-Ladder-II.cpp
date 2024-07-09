class Solution {
private:
    bool check(set<string> &list,string word){
        if(list.find(word)!=list.end()){
            return true;
        }
        return false;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        set<string> list(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        vector<vector<string>> ans;
        q.push({beginWord});
        int prevLen = q.front().size();
        vector<string> del;
        while(!q.empty()){
            int currLen = q.front().size();
            if(prevLen!=currLen){
                for(auto it : del){
                    list.erase(it);
                }
                del.clear();
                prevLen=currLen;
            }
            vector<string> lastList = q.front();
            string lastWord = lastList.back();
            q.pop();
            if(lastWord==endWord){
                ans.push_back(lastList);
                continue;
            }
            for(int i=0;i<lastWord.size();i++){
                for(int j=0;j<26;j++){
                    string temp = lastWord;
                    temp[i]='a'+j;
                    if(check(list,temp)){
                        lastList.push_back(temp);
                        del.push_back(temp);
                        q.push(lastList);
                        lastList.pop_back();
                    }
                }
            }

        }
        return ans;
    }
};
