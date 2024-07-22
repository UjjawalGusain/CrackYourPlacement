// https://leetcode.com/problems/group-anagrams/description/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> m;

        vector<string> ss(strs.begin(), strs.end());
        vector<vector<string>> res;
        for(int i = 0; i<ss.size(); i++) {
            sort(ss[i].begin(), ss[i].end());
            m[ss[i]].push_back(i);
        }
        int k = 0;
        for(auto &pair : m) {
            vector<string> arr;
            for(int i = 0; i<pair.second.size(); i++)
                arr.push_back(strs[pair.second[i]]);
            res.push_back(arr);
            k++;
        }

        return res;
    }
};