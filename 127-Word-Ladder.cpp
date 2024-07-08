class Solution {
private:
    bool check(set<string> &list,string word){
        if(list.find(word)!=list.end()){
            return true;
        }
        return false;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> list;
        for(auto it : wordList){
            list.insert(it);
        }
        if(check(list,endWord)==false){
            return 0;
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
                for(int i=0;i<word.size();i++){
                    string tempWord=word;
                    for(int j=0;j<26;j++){
                        tempWord[i]='a'+j;
                        if(tempWord==endWord){
                            return level+1;
                        }
                        else if(check(list,tempWord)){
                        q.push({tempWord,level+1});
                        list.erase(tempWord);
                        }
                    }
                }
            }

        return 0;
    }
};
