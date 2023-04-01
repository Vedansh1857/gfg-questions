
class Solution
{
public:
    int solveRec(int n){
        // BASE CASE...
        int MOD = 1000000007;
        if(n==1 || n==0) return 1;
        if(n<=0) return 0;
        int single = solveRec(n-1);
        int pair = (n-1)*solveRec(n-2);
        int ans = (single+pair)%MOD;
        return ans;
    }
    long long solveMem(int n,vector<long long>& dp){
        // BASE CASE...
        long long int MOD = 1000000007;
        if(n==1 || n==0) return 1;
        if(n<0) return 0;
        if(dp[n] != -1) return dp[n];
        long long single = solveMem(n-1,dp);
        long long pair = (n-1)*solveMem(n-2,dp);
        dp[n] = (single+pair)%MOD;
        return dp[n];
    }
    long long solveTab(int n){
        long long int MOD = 1000000007;
        vector<long long> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            long long single = dp[i-1];
            long long pair = (i-1)*dp[i-2];
            dp[i] = (single+pair)%MOD;
        }
        return dp[n];
    }
    int countFriendsPairings(int n) { 
        // code here
        // return solveRec(n);
        
        // vector<long long> dp(n+1,-1);
        // return solveMem(n,dp);
        
        return solveTab(n);
    }
};
