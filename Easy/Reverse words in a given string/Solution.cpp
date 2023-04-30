class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S){ 
        // code here
        string ans = "";
        string tmp = "";
        for(int i=S.length();i>=0;i--){
            if(S[i] == '.'){
                reverse(tmp.begin(),tmp.end());
                ans += tmp;
                ans.push_back('.');
                tmp.clear();
            }
            else tmp.push_back(S[i]);
        }
        // For the First word of the given string.
        // The first word will not be reversed by the above process as there is no dot before it.
        reverse(tmp.begin(),tmp.end());
        ans += tmp;
        return ans;
    }
};
