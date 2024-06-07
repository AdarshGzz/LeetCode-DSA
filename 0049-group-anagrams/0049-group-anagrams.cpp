class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> groups;

        for(auto i: strs){
            string s = i;
            sort(s.begin(),s.end());
            groups[s].push_back(i);
        }

        vector<vector<string>> result;
        for(auto g:groups){
            result.push_back(g.second);
        }

        return result;
    }
        
};