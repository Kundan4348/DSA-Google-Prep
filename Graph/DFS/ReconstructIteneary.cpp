/* We keep a multiset here which can have duplicates values

both map and multiset are sorted

we just need to iterate over the multiset using dfs and once we iterate over one then do not move to the same

place again we are making sure about this by erasing the value once we visit it */



class Solution {
    void dfs(string node,map<string,multiset<string>>& map,vector<string>& ans){
        vector<string> temp;
        for(string str:map[node]){
            temp.push_back(str);
        }
        for(auto str: temp){
            if(map[node].find(str)!=map[node].end()){
                map[node].erase(map[node].find(str));
                dfs(str,map,ans);
            }
        }
        ans.push_back(node);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,multiset<string>> map;

        for(int i=0;i<tickets.size();++i){
            string a = tickets[i][0];
            string b = tickets[i][1];
            map[a].insert(b);
        }

        //just do dfs iterations
        vector<string> ans;
        dfs("JFK",map,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};