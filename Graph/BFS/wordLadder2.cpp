class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> wordMap;
        vector<vector<string>> res;
        for(int i=0;i<wordList.size();++i){
            wordMap.insert(wordList[i]);
        }

        queue<vector<string>> q;
        q.push({beginWord});

        while(!q.empty()){

            int len = q.size();
            for(int i=0;i<len;++i){
                vector<string> currList = q.front();
                q.pop();
                string originalStr = currList.back();
                if(originalStr == endWord){
                    if(res.size() == 0){
                        res.push_back(currList);
                    } else if(currList.size() == res[0].size()){
                        res.push_back(currList);
                    }
                }

                for(int j=0;j<originalStr.size();++j){
                     string currStr = originalStr;
                     for(char ch='a';ch<='z';++ch){
                        currStr[j] = ch;
                        if(wordMap.count(currStr) > 0){
                            currList.push_back(currStr);
                            q.push(currList);
                            currList.pop_back();
                        }
                    }
                }
               wordMap.erase(originalStr);
            }   
        }

        return res;
    }
};

1 2
3 4
Expected Output
Download
4999949998

704982702