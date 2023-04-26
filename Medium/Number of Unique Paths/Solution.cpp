//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int solveRec(int r,int d,int m,int n){
        // BASE CASE...
        if(r==m-1 && d==n-1) return 1;
        if(r >= m || d >= n) return 0;   
        int ans = solveRec(r+1,d,m,n)+solveRec(r,d+1,m,n);
        return ans;
    }
    int solveMem(int r,int d,int m,int n,vector<vector<int>>& dp){
        // BASE CASE...
        if(r==m-1 && d==n-1) return 1;
        if(r >= m || d >= n) return 0;   
        if(dp[r][d] != -1) return dp[r][d];
        int ans = solveMem(r+1,d,m,n,dp)+solveMem(r,d+1,m,n,dp);
        return dp[r][d] = ans;
    }
    int NumberOfPath(int a, int b){
        //code here
        // return solveRec(0,0,a,b);
        
        vector<vector<int>> dp(a+1,vector<int>(b+1,-1));
        return solveMem(0,0,a,b,dp);
    }
};
