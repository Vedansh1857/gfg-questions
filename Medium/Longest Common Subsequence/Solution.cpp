// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int solveRec(string& s1, string& s2, int i,int j){
        // BASE CASE...
        if(i == s1.size() || j == s2.size()) return 0;
        if(s1[i] == s2[j]) return solveRec(s1,s2,i+1,j+1)+1;
        int textOne = solveRec(s1,s2,i+1,j);
        int textTwo = solveRec(s1,s2,i,j+1);
        return max(textOne,textTwo);
    }
    int solveMem(string& s1, string& s2, int i,int j, vector<vector<int>>& dp){
        // BASE CASE...
        if(i == s1.size() || j == s2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return solveMem(s1,s2,i+1,j+1,dp)+1;
        int textOne = solveMem(s1,s2,i+1,j,dp);
        int textTwo = solveMem(s1,s2,i,j+1,dp);
        dp[i][j] = max(textOne,textTwo);
        return dp[i][j];
    }
    int solveTab(string& text1, string& text2){
        vector<vector<int>> dp(text1.size()+1, vector<int> (text2.size()+1,0));
        for(int i=text1.size()-1;i>=0;i--){
            for(int j=text2.size()-1;j>=0;j--){
                int ans = 0;
                if(text1[i] == text2[j]) ans = dp[i+1][j+1]+1;
                else{
                    int textOne = dp[i+1][j];
                    int textTwo = dp[i][j+1];
                    ans = max(textOne,textTwo);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int lcs(int x, int y, string s1, string s2){
        // your code here
        
        // solveRec(s1,s2,0,0);
        
        // vector<vector<int>> dp(x+1, vector<int> (y+1,-1));
        // return solveMem(s1,s2,0,0,dp);
        
        return solveTab(s1,s2);
    }
};
