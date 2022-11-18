class Solution{
  public:
    vector<vector<string>> Anagrams(vector<string>& string_list) {
        //code here
        unordered_map<string, vector<string>> m;
        // iterate each string
        for(auto& x : string_list) {
            string t = x;
            sort(t.begin(), t.end());
            m[t].push_back(x);
        }
        vector<vector<string>> ans;
        // x.second is the array of the anagrams under the key `x.first`
        for(auto& x : m) ans.push_back(x.second);
        return ans;
    }
};
