
class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    // #DEFINE MOD 1e9+7
    long long solveRec(int n){
        // Base case...
        if(n==0) return 1;
        if(n==1) return 1;
        if(n==2) return 2;
        return solveRec(n-1)+solveRec(n-2)+solveRec(n-3);
    }
    long long solveMem(int n,vector<long long int>& dp){
        // Base case...
        if(n==0) return 1;
        if(n==1) return 1;
        if(n==2) return 2;
        if(dp[n] != -1) return dp[n];
        long long MOD = 1000000007;
        dp[n] = solveMem(n-1,dp)%MOD+solveMem(n-2,dp)%MOD+solveMem(n-3,dp)%MOD;
        return dp[n]%MOD;
    }
    long long countWays(int n){
        // your code here
        // return solveRec(n);
        vector<long long int> dp(n+1,-1);
        return solveMem(n,dp);
    }
};
