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
    int lcs(int x, int y, string s1, string s2){
        // your code here
        
        // solveRec(s1,s2,0,0);
        
        vector<vector<int>> dp(x+1, vector<int> (y+1,-1));
        return solveMem(s1,s2,0,0,dp);
    }
};
