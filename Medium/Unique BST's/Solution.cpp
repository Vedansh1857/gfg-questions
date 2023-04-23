class Solution
{
    public:
    //Function to return the total number of possible unique BST.
    int solveRec(int n){
        // BASE CASE...
        if(n == 1 || n == 0) return 1; // When there is only one or no node then there is only one way.
        if(n == 2) return 2; // When there are only two nodes no. of ways are 2 only.
        int ans = 0;
        // Here in the loop i is the root node. So, each number till n is a root at a tym and we call recursion for numbers before i (i-1) and after i (n-i) to get the no.of ways
        for(int i=1;i<=n;i++) ans += solveRec(i-1) * solveRec(n-i);
        return ans;
    }
    int solveMem(int n,vector<int>& dp){
        // BASE CASE...
        int MOD = 1000000007;
        if(n == 1 || n == 0) return 1;
        if(n == 2) return 2;
        if(dp[n] != -1) return dp[n];
        long long ans = 0;
        for(int i=1;i<=n;i++) ans += solveMem(i-1,dp) * solveMem(n-i,dp);
        return dp[n] = ans%MOD;
    }
    long long solveTab(int n){
        const int MOD = 1e9+7;
        vector<long long> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        // dp[2]=2;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++) dp[i] = (dp[i]+((dp[j-1]%MOD) * (dp[i-j]%MOD))%MOD)%MOD;
        }
        return dp[n]%MOD;
    }
    int numTrees(int N){
        // Your code here
        // int MOD = 1000000007;
        // return solveRec(N);
        
        // vector<int> dp(N+1,-1);
        // return solveMem(N,dp);
        
        return solveTab(N);
    }
};

"C:\Users\vedan\OneDrive\Pictures\Screenshots\Screenshot (2).png"
